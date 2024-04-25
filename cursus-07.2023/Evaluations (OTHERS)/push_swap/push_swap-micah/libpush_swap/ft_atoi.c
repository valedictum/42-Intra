/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:05:58 by mickim            #+#    #+#             */
/*   Updated: 2023/03/30 19:11:18 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

long	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
		{
			sign = -1;
		}
		else
		{
			sign = 1;
		}
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str++ - '0');
	}
	return (result * sign);
}
