/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:38:42 by tday              #+#    #+#             */
/*   Updated: 2024/03/17 16:39:30 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	t_msh	*msh;
	char	*input = NULL;
	int		exit_status;

	(void)argv;
	if (argc != 1)
		error_exit("Incorrect number of arguments");
	msh = init_minishell(envv);
	while (1)
	{
		input = get_input(msh, "prompt: ");
		if (input[0] == '1') // enter 1 to exit input loop
		{
			free(input);
			break ;
		}
		add_tokens_to_list(msh, input);
		//extract_commands(msh);
		if (ft_strcmp((char *)msh->tokens->data, "echo") == 0)
			ft_echo(msh);
		if (ft_strcmp((char *)msh->tokens->data, "env") == 0)
			ft_env(msh);
		if (ft_strcmp((char *)msh->tokens->data, "pwd") == 0)
			ft_pwd(msh);
		if (ft_strcmp((char *)msh->tokens->data, "cd") == 0)
            ft_cd(msh);
		if (ft_strcmp((char *)msh->tokens->data, "exit") == 0)
		{
			if (msh->tokens->next != NULL)
			{
				exit_status = ft_atoi((char *)msh->tokens->next->data);
				if (exit_status > 255 || exit_status < 0 || !exit_status)
					error_exit("Invalid exit status");
				else
				{
					lst_del_all(&(msh)->tokens, free_string);
					cleanup_and_exit(input, msh, exit_status);
					continue ;
				}
			}
			else
				cleanup_and_exit(input, msh, exit_status);
		}
		if (ft_strcmp((char *)msh->tokens->data, "export") == 0)
			ft_export(msh);
		if (msh->tokens)
		{
			debug("still tokens");
			lst_del_all(&(msh->tokens), free_string);
			msh->tokens = NULL;
		}
		free(input);
	}
	free_everything(msh);
//	debug("free_everything successful");
	return (0);
}
