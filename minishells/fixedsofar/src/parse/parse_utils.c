/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:23:49 by atang             #+#    #+#             */
/*   Updated: 2024/04/14 16:56:19 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	Summary
	checks if a given string is a redirection symbol.

	Inputs
	[char *] str: The string to be checked for redirection symbol.

	Outputs
	returns true if the given string is a redirection symbol, and false
	if it's not.
*/
bool	is_redirect(char *str)
{
	if (!ft_strcmp(str, "<") || !ft_strcmp(str, "<<") || \
		!ft_strcmp(str, ">") || !ft_strcmp(str, ">>"))
		return (true);
	else
		return (false);
}

int	get_open_flags(bool is_append)
{
	int	open_flags;

	open_flags = O_CREAT | O_WRONLY;
	if (is_append)
		open_flags |= O_APPEND;
	else
		open_flags |= O_TRUNC;
	return (open_flags);
}
