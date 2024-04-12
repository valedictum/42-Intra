/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:11:15 by tday              #+#    #+#             */
/*   Updated: 2024/04/12 22:52:07 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees all allocated memory and exits the program with a specified exit
	status.

	Inputs
	[t_msh *] msh: the main structure.
	[int] exit_status: the exit status of the program.

	Outputs
	none.
*/

void	clean_exit(t_msh *msh, int exit_status)
{
	free_everything(msh);
	exit(exit_status);
}
