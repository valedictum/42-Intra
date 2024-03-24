/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:38:45 by tday              #+#    #+#             */
/*   Updated: 2024/03/24 10:57:45 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_node_value(t_dlist *envvar_node, char *new_value)
{
	t_envv	*envv_struct;

	envv_struct = (t_envv *)envvar_node->data;
	if (envv_struct->env_value != NULL)
		free(envv_struct->env_value);
	envv_struct->env_value = new_value;
	//NEW from here (free only if new_value != NULL)
    if (new_value != NULL)
    {
        envv_struct->env_value = ft_strdup(new_value);
        if (envv_struct->env_value == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        envv_struct->env_value = NULL;
    }
}
