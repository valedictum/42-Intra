/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 22:52:11 by tday              #+#    #+#             */
/*   Updated: 2024/04/12 22:53:50 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	frees all allocated memory and exits the program while printing an error
	message to the terminal.

	Inputs
	[t_msh *] msh: the main structure.
	[char *] error_message: the error message to be printed to the terminal.

	Outputs
	none.
*/

/*
// OG TAS CODE
void	msh_error_exit(t_msh *msh, char *error_message)
{
	free_everything(msh);
	error_exit(error_message);
}
*/

void msh_error_exit(t_msh *msh, char *error_message)
{
	free_everything(msh);
	ft_printf(RED "%s\n" DEF, error_message);
	exit(msh->last_exit_status);
}
