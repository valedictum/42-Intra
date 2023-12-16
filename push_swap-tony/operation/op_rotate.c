/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:18:15 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:11:55 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Rotate a
void	ra(int **a, int *size_a)
{
	int	first_element;
	int	i;

	if (*size_a > 1)
	{
		first_element = (*a)[0];
		i = 0;
		while (i < (*size_a) - 1)
		{
			(*a)[i] = (*a)[i + 1];
			i++;
		}
		(*a)[*size_a - 1] = first_element;
		write(1, "ra\n", 3);
	}
}

// Rotate b
void	rb(int **b, int *size_b)
{
	int	first_element;
	int	i;

	if (*size_b > 1)
	{
		first_element = (*b)[0];
		i = 0;
		while (i < (*size_b) - 1)
		{
			(*b)[i] = (*b)[i + 1];
			i++;
		}
		(*b)[*size_b - 1] = first_element;
		write(1, "rb\n", 3);
	}
}

// Rotate both stacks
void	rr(int **a, int *size_a, int **b, int *size_b)
{
	int	first_element_a;
	int	first_element_b;
	int	i;
	int	j;

	if (*size_a > 1 && *size_b > 1)
	{
		first_element_a = (*a)[0];
		first_element_b = (*b)[0];
		i = -1;
		while (++i < (*size_a) - 1)
		{
			(*a)[i] = (*a)[i + 1];
		}
		(*a)[*size_a - 1] = first_element_a;
		j = -1;
		while (++j < (*size_b) - 1)
		{
			(*b)[j] = (*b)[j + 1];
		}
		(*b)[*size_b - 1] = first_element_b;
	}
	write(1, "rr\n", 3);
}
