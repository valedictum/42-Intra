/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:08:49 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:12:53 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(int **a, int *size_a, int **b, int *size_b)
{
	if ((*size_a) <= 5)
	{
		while ((*size_a) > 3)
		{
			find_and_push_smallest(a, size_a, b, size_b);
		}
		sort_three(a, size_a);
		while ((*size_b) > 0)
		{
			pa(a, size_a, b, size_b);
		}
	}
}

void	find_and_push_smallest(int **a, int *size_a, int **b, int *size_b)
{
	int	smallest_index;

	smallest_index = find_smallest_index(*a, *size_a);
	while (smallest_index > 0)
	{
		if (smallest_index < (*size_a) / 2)
			ra(a, size_a);
		else
			rra(a, size_a);
		smallest_index = find_smallest_index(*a, *size_a);
	}
	pb(a, size_a, b, size_b);
}

int	find_smallest_index(int *array, int size)
{
	int	smallest_index;
	int	i;

	smallest_index = 0;
	i = 1;
	while (i < size)
	{
		if (array[i] < array[smallest_index])
		{
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}
