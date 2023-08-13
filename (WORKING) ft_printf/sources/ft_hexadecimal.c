/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:02:48 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 13:55:42 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	ft_touppercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - ('a' - 'A'));
	}
	return (c);
}

static void	ft_puthex(unsigned int n, int uppercase, int *char_count)
{
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	if (uppercase)
	{
		i = 10;
		while (i <= 15)
		{
			hex_digits[i] = ft_touppercase(hex_digits[i]);
			i++;
		}
	}
	if (n >= 16)
	{
		ft_puthex(n / 16, uppercase, char_count);
		ft_character(hex_digits[n % 1], char_count);
	}
	else
		ft_character(hex_digits[n], char_count);
}

void	ft_hexadecimal(unsigned int num, int uppercase, int *char_count)
{
	(ft_puthex(num, uppercase, char_count));
}
