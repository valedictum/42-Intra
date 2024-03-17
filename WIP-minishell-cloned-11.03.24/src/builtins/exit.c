/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:32:22 by atang             #+#    #+#             */
/*   Updated: 2024/03/17 16:39:23 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void		ft_exit(int exit_status)
{
	if (exit_status == 0)
		exit_status = EXIT_SUCCESS;
	printf("exit\n");
	exit(exit_status);
}

void cleanup_and_exit(char *input, t_msh *msh, int exit_status)
{
    if (input)
        free(input);
    free_everything(msh);
    ft_exit(exit_status);
}
