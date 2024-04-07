/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 14:51:30 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

//extern int last_exit_status;

int	main(int argc, char **argv, char **envv)
{
	t_msh	*msh;
	char	*input = NULL;

	(void)argv;
	if (argc != 1)
		error_exit("Incorrect number of arguments");
	msh = init_minishell(envv);
	setup_signal_handlers(); // <- (CTRL-C and CTRL-\) ADD this line
	while (1)
	{
		input = get_input(msh, "prompt: ");
		// (CTRL-C) DELETE the line BELOW
		// if (input && input[0] == '1') // enter 1 to exit input loop, remove later
		if (!input)
			continue;
		if (input[0] == '1')
		{
			free(input);
			break ;
		}
		process_input(msh, input);
		execute_commands(msh);
		printf("Last exit status: %d\n", last_exit_status);
		msh->num_of_cmds = 0;
		free_input(msh, input);
	}
	//printf("Last exit status: %d\n", last_exit_status);
	reset_signal_handlers(); // <- (CTRL-C and CTRL-\) ADD this line
	free_everything(msh);
	return (0);
}
