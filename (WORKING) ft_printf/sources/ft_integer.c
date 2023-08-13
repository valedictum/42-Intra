/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:36:15 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 15:55:31 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_integer(int num, int *char_count)
{
	if (num < 0)
	{
		if (num == -2147483648)
		{
			write(1, "2147483648", 10);
			return ;
		}
		ft_character('-', char_count);
		num = -num;
	}
	if (num >= 10)
	{
		ft_integer(num / 10, char_count);
	}
	ft_character('0' + num % 10, char_count);
}
