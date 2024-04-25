/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/04/14 16:15:33 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	t_msh	*msh;

	(void)argv;
	if (argc != 1)
		error_exit("Incorrect number of arguments");
	msh = init_minishell(envv);
	while (1)
	{
		msh->input = get_input(msh);
		debug("after get input");
		if (ft_strcmp(msh->input, "") == 0)
			continue ;
		process_input(msh);
		execute_commands(msh);
		msh->num_of_cmds = 0;
		free_input(msh);
	}
	reset_signal_handlers();
	free_everything(msh);
	return (0);
}
