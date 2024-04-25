/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:27:29 by fsalimba          #+#    #+#             */
/*   Updated: 2023/04/29 12:10:52 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, char type);
int		ft_len_hex(unsigned int n);

int	ft_put_hex(unsigned int n, char type)
{
	int	len;

	len = 0;
	ft_print_hex(n, type);
	len += ft_len_hex(n);
	return (len);
}

void	ft_print_hex(unsigned int n, char type)
{
	if (n >= 16)
	{
		ft_print_hex(n / 16, type);
		ft_print_hex(n % 16, type);
	}
	else
	{
		if (n <= 9)
			ft_put_c(n + '0');
		else
		{
			if (type == 'x')
				ft_put_c(n - 10 + 'a');
			if (type == 'X')
				ft_put_c(n - 10 + 'A');
		}
	}
}

int	ft_len_hex(unsigned int n)
{
	unsigned long	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
