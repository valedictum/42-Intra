/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:06:14 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 13:56:07 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *s, int *char_count)
{
	size_t	i;

	if (!s)
	{
		write(1, "(null)", 6);
		(*char_count) += 6;
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_character(s[i], char_count);
		i++;
	}
}
