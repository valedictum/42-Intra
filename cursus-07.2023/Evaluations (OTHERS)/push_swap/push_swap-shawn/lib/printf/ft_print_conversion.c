/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:05:00 by jlyu              #+#    #+#             */
/*   Updated: 2023/07/25 10:42:46 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_chr(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	if (str == NULL)
		return (ft_print_str("(null)"));
	i = 0;
	while (str[i])
	{
		ft_print_chr(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_point(unsigned long long pointer)
{
	int	i;

	i = ft_print_str("0x");
	i += print_hexa(pointer);
	return (i);
}

int	ft_print_undec(unsigned int number)
{
	int	i;

	i = 0;
	if (number < 10)
		return (ft_print_chr('0' + number));
	else
	{
		i += ft_print_undec(number / 10);
		i += ft_print_undec(number % 10);
	}
	return (i);
}

int	ft_print_dec(int number)
{
	int	i;

	if (number < 0)
	{
		i = ft_print_chr('-');
		i += ft_print_undec(-number);
	}
	else
		i = ft_print_undec(number);
	return (i);
}
