/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:09:28 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:12:42 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	copy_stack(int *copy_a, int *copy_a_ref, int **a, int *size_a)
{
	int	i;

	i = 0;
	while (i < (*size_a))
	{
		copy_a[i] = (*a)[i];
		copy_a_ref[i] = (*a)[i];
		i++;
	}
}

void	bubble_sort(int *array, int *size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (*size))
	{
		j = i + 1;
		while (j < (*size))
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	reassign(int **a, int *size_a, int *copy_a, int *copy_a_ref)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*size_a))
	{
		j = 0;
		while (j < (*size_a))
		{
			if (copy_a_ref[i] == copy_a[j])
			{
				(*a)[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	sort_bit(int **a, int *size_a, int **b, int *size_b)
{
	int	max_num;
	int	max_bit;
	int	*bit;

	max_num = (*size_a) - 1;
	max_bit = 0;
	while ((max_num >> max_bit) != 0)
		++max_bit;
	bit = malloc(2 * sizeof(int));
	bit[0] = -1;
	while (++bit[0] < max_bit)
	{
		bit[1] = -1;
		while (++bit[1] < (max_num + 1))
		{
			if ((((*a)[0] >> bit[0]) & 1))
				ra(a, size_a);
			else
				pb(a, size_a, b, size_b);
		}
		while ((*size_b) != 0)
			pa(a, size_a, b, size_b);
	}
	free(bit);
}

void	sort_complex(int **a, int *size_a, int **b, int *size_b)
{
	int	*copy_a;
	int	*copy_a_ref;

	copy_a = malloc((*size_a) * sizeof(int));
	copy_a_ref = malloc((*size_a) * sizeof(int));
	copy_stack(copy_a, copy_a_ref, a, size_a);
	bubble_sort(copy_a, size_a);
	reassign(a, size_a, copy_a, copy_a_ref);
	free(copy_a);
	free(copy_a_ref);
	sort_bit(a, size_a, b, size_b);
}
