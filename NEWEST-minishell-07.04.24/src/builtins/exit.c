/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:03:45 by sentry            #+#    #+#             */
/*   Updated: 2024/04/07 10:43:36 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


// 06.04.24 - ADDED this fn for last_exit_status (ADD to .h) 
void	set_last_exit_status(t_msh *msh, int status)
{
	if (WIFEXITED(status))
	{
		msh->last_exit_status = WEXITSTATUS(status); // Process exited normally
	}
	else if (WIFSIGNALED(status)) // Signal termination statuses are usually 128-255 (normal exit statuses are usually 0-127)
	{
		msh->last_exit_status = WTERMSIG(status) + 128; // Process terminated by a signal;
	}
	else
	{
		msh->last_exit_status = status; // Other cases e.g. process was stopped or continued
	}
}

void	ft_exit(t_msh *msh, t_cmd *cmd)
{
	int		exit_status;

	if (!cmd->arguments)
		//exit_status = EXIT_SUCCESS; <- DELETED this line and ADDED the below
		msh->last_exit_status = EXIT_SUCCESS;
	else
	{
		exit_status = ft_atoi((char *)cmd->arguments->data);
		if (!exit_status)
			msh_error_exit(msh, "exit\nvalid numeric argument required");
		else if (cmd->arguments->next != NULL)
			msh_error_exit(msh, "exit\ntoo many arguments");
		msh->last_exit_status = exit_status; // <- ADDED this line
	}
	ft_printf("exit\n");
	exit(msh->last_exit_status); // <- CHANGED this line to msh->last_exit_status (from exit(exit_status))
}
