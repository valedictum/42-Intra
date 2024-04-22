/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:17:35 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:11:17 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push b to a
void	pa(int **a, int *size_a, int **b, int *size_b)
{
	int	i;

	if (*size_b > 0)
	{
		(*size_a)++;
		i = (*size_a) - 1;
		while (i > 0)
		{
			(*a)[i] = (*a)[i - 1];
			i--;
		}
		(*a)[0] = (*b)[0];
		i = 0;
		while (i < (*size_b))
		{
			(*b)[i] = (*b)[i + 1];
			i++;
		}
		(*size_b)--;
		write(1, "pa\n", 3);
	}
}

// Push a to b
void	pb(int **a, int *size_a, int **b, int *size_b)
{
	int	i;

	if (*size_a > 0)
	{
		(*size_b)++;
		i = (*size_b) - 1;
		while (i > 0)
		{
			(*b)[i] = (*b)[i - 1];
			i--;
		}
		(*b)[0] = (*a)[0];
		i = 0;
		while (i < (*size_a))
		{
			(*a)[i] = (*a)[i + 1];
			i++;
		}
		(*size_a)--;
		write(1, "pb\n", 3);
	}
}
