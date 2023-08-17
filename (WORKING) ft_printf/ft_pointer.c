/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:04:44 by atang             #+#    #+#             */
/*   Updated: 2023/08/17 15:32:45 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer(size_t pointer, int *char_count)
{
	char	string[25];
	int		i;
	char	*hexadecimal_base;

	hexadecimal_base = "0123456789abcdef";
	i = 0;
	ft_character('0', char_count);
	ft_character('x', char_count);
	if (pointer == 0)
	{
		ft_character('0', char_count);
		return ;
	}
	while (pointer != 0)
	{
		string[i] = hexadecimal_base [pointer % 16];
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_character(string[i], char_count);
}
