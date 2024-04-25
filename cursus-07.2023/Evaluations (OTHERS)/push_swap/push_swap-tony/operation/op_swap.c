/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:18:27 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:12:09 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int **a)
{
	int	temp;

	temp = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(int **b)
{
	int	temp;

	temp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(int **a, int **b)
{
	int	temp_a;
	int	temp_b;

	temp_a = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp_a;
	temp_b = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = temp_b;
	write(1, "ss\n", 3);
}
