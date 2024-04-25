/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_internet_sort_utilities.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:57:53 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 15:57:54 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_a(t_stack *stack)
{
	int			a;
	t_number	*current;

	current = stack->number;
	a = 0;
	while (true)
	{
		a += current->value;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	a /= stack->size;
	return (a);
}

int	calculate_x(t_stack *stack, int a)
{
	int			x;
	int			size;
	t_number	*current;

	current = stack->number;
	x = 0;
	size = 0;
	while (true)
	{
		if (current->value <= a)
		{
			x += current->value;
			size++;
		}
		current = current->next;
		if (current == stack->number)
			break ;
	}
	x /= size;
	return (x);
}
