/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:31:20 by fsalimba          #+#    #+#             */
/*   Updated: 2023/04/29 12:11:13 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long int ptr);
int		ft_len_ptr(unsigned long int ptr);

int	ft_put_ptr(unsigned long int ptr)
{
	int	len;

	len = 0;
	len += ft_put_str("0x");
	ft_print_ptr(ptr);
	len += ft_len_ptr(ptr);
	return (len);
}

void	ft_print_ptr(unsigned long int ptr)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_put_c(ptr + '0');
		else
			ft_put_c(ptr - 10 + 'a');
	}
}

int	ft_len_ptr(unsigned long int ptr)
{
	unsigned long	len;

	len = 0;
	if (ptr == 0)
		len++;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}
