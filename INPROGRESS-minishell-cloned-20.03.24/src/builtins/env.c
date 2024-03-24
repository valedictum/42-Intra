/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:24:21 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 10:57:47 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	prints the key-value pair of an environment variable separated by an '='.

	Inputs
	[t_envv *] envv_element: an environment variable.

	Outputs
	none. the function only prints the key-value pair of the environment
	variable.
*/
static void	print_envvar(t_envv *envv_element)
{
	if (envv_element != NULL)
	{
		ft_printf("%s=%s\n", envv_element->env_key, \
		envv_element->env_value);
	}
}

/*
	Summary
	prints the key-value pairs of each element in a given doubly linked list.

	Inputs
	[t_msh *] msh: the main struct of minishell contianing a doubly linked
		list of cloned environment variables.

	Outputs
	none. the function only prints the key-value pairs of the environment
	variables.
*/
void	ft_env(t_msh *msh)
{
	t_dlist	*current;

	current = msh->envvar;
	while (current)
	{
		print_envvar((t_envv *)current->data);
		current = current->next;
	}
}
