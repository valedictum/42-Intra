/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:54 by jlyu              #+#    #+#             */
/*   Updated: 2023/07/25 10:19:44 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(unsigned long long pointer)
{
	int	i;

	i = 0;
	if (pointer < 16)
	{
		if (pointer > 9)
			return (ft_print_chr('a' + (pointer - 10)));
		return (ft_print_chr('0' + pointer));
	}
	else
	{
		i += print_hexa(pointer / 16);
		i += print_hexa(pointer % 16);
	}
	return (i);
}

int	print_long_hexa(unsigned int pointer, char flag)
{
	int	i;

	i = 0;
	if (pointer < 16)
	{
		if (pointer > 9)
		{
			if (flag == 'x')
				return (ft_print_chr('a' + (pointer - 10)));
			return (ft_print_chr('A' + (pointer - 10)));
		}
		return (ft_print_chr('0' + pointer));
	}
	else
	{
		i += print_long_hexa(pointer / 16, flag);
		i += print_long_hexa(pointer % 16, flag);
	}
	return (i);
}
