/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:24:21 by tday              #+#    #+#             */
/*   Updated: 2024/04/12 20:41:30 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	prints the key-value pair of an environment variable separated by an '='.

	Inputs
	[int] fd: the file descriptor to output to.
	[t_envv *] envv_element: an environment variable.

	Outputs
	none. the function only prints the key-value pair of the environment
	variable.
*/
static void	print_envvar(int fd, t_envv *envv_element)
{
	if (envv_element != NULL)
	{
		ft_printf_fd(fd, "%s=%s\n", envv_element->env_key, \
		envv_element->env_value);
	}
}

/*
	Summary
	prints the key-value pairs of each element in a given doubly linked list.

	Inputs
	[t_msh *] msh: the main struct of minishell contianing a doubly linked
		list of cloned environment variables.
	[t_cmd *] cmd: the command struct containing the data from the current
		command.

	Outputs
	none. the function only prints the key-value pairs of the environment
	variables.
*/

/*
// OG TAS CODE
void	ft_env(t_msh *msh, t_cmd *cmd)
{
	t_dlist	*current;

	current = msh->envvar;
	while (current)
	{
		print_envvar(cmd->out_fd, (t_envv *)current->data);
		current = current->next;
	}
}
*/

// Modified - added last_exit_status and changed to int
int	ft_env(t_msh *msh, t_cmd *cmd)
{
	t_dlist	*current;

	current = msh->envvar;
	while (current)
	{
		print_envvar(cmd->out_fd, (t_envv *)current->data);
		current = current->next;
	}
	msh->last_exit_status = 0;
	return (0);
}