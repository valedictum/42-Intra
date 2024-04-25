/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:52:54 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:11:00 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

void	init_stack(int **stack, int *size, int capacity, char **temp)
{
	int		i;
	long	num;

	*stack = malloc(capacity * (sizeof(int)));
	if (*stack == NULL)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	*size = 0;
	i = 0;
	while (i < capacity)
	{
		num = ft_atoi(temp[i]);
		check_number(num);
		(*stack)[*size] = num;
		(*size)++;
		i++;
	}
}

void	check_if_sort(int *arr, int size)
{
	int	i;

	i = 0;
	while (arr[i] < arr[i + 1] && i < size - 1)
	{
		i++;
	}
	if (size - i == 1)
	{
		exit (0);
	}
}
