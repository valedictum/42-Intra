/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:37:21 by atang             #+#    #+#             */
/*   Updated: 2023/08/13 13:56:15 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_unsigned_decimal(unsigned int num, int *char_count)
{
	if (num >= 10)
		ft_unsigned_decimal(num / 10, char_count);
	ft_character('0' + num % 10, char_count);
}
