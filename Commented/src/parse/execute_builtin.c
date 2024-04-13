/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:48:40 by tday              #+#    #+#             */
/*   Updated: 2024/03/20 22:32:14 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	execute_builtin(t_msh *msh)
{
	t_cmd	*cmd_struct = (t_cmd *)msh->cmd_queue->data;

	if (!msh->cmd_queue)
	{
		error("execute_builtin no cmd_queue");
		return ;
	}
	if (ft_strcmp(cmd_struct->command, "env") == 0)
		ft_env(msh);
	else if (ft_strcmp(cmd_struct->command, "pwd") == 0)
		ft_pwd(msh);
	else if (ft_strcmp(cmd_struct->command, "export") == 0)
		ft_export(msh);
	else if (ft_strcmp(cmd_struct->command, "echo") == 0)
		ft_echo(msh);
	else if (ft_strcmp(cmd_struct->command, "exit") == 0)
		ft_exit(msh);
	else if (ft_strcmp(cmd_struct->command, "cd") == 0)
		ft_cd(msh);
	else if (ft_strcmp(cmd_struct->command, "unset") == 0)
	{
		error("unset not coded yet");
		return ;
	}
}