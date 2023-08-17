/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:02:48 by atang             #+#    #+#             */
/*   Updated: 2023/08/17 18:56:08 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int n, int uppercase, int *char_count)
{
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16, uppercase, char_count);
		ft_character(hex_digits[n % 16], char_count);
	}
	else
		ft_character(hex_digits[n], char_count);
}

void	ft_hexadecimal(unsigned int num, int uppercase, int *char_count)
{
	ft_puthex(num, uppercase, char_count);
}
