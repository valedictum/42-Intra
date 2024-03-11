/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:32:22 by atang             #+#    #+#             */
/*   Updated: 2024/03/11 16:39:32 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void		ft_exit(int exit_status)
{
	if (exit_status < 0)
		exit_status = EXIT_SUCCESS;
	printf("exit\n");
	exit(exit_status);
}
