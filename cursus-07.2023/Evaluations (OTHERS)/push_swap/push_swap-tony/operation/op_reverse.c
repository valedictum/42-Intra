/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:17:46 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:11:43 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Reverse rotate a
void	rra(int **a, int *size_a)
{
	int	last_element;
	int	i;

	if (*size_a > 1)
	{
		last_element = (*a)[*size_a - 1];
		i = (*size_a);
		while (--i > 0)
		{
			(*a)[i] = (*a)[i - 1];
		}
		(*a)[0] = last_element;
		write(1, "rra\n", 4);
	}
}

// Reverse rotate b
void	rrb(int **b, int *size_b)
{
	int	last_element;
	int	i;

	if (*size_b > 1)
	{
		last_element = (*b)[*size_b - 1];
		i = (*size_b);
		while (--i > 0)
		{
			(*b)[i] = (*b)[i - 1];
		}
		(*b)[0] = last_element;
		write(1, "rrb\n", 4);
	}
}

// Reverse rotate both stacks
void	rrr(int **a, int *size_a, int **b, int *size_b)
{
	int	last_element_a;
	int	last_element_b;
	int	i;
	int	j;

	if (*size_a > 1 && *size_b > 1)
	{
		last_element_a = (*a)[*size_a - 1];
		last_element_b = (*b)[*size_b - 1];
		i = (*size_a);
		while (--i > 0)
		{
			(*a)[i] = (*a)[i - 1];
		}
		(*a)[0] = last_element_a;
		j = (*size_b);
		while (--j > 0)
		{
			(*b)[j] = (*b)[j - 1];
		}
		(*b)[0] = last_element_b;
		write(1, "rrr\n", 4);
	}
}
