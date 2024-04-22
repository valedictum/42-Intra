/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:44 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:30:45 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_int(t_stack *stack)
{
	t_number	*current;
	int			max;

	if (stack->size == 0)
		return (0);
	current = stack->number;
	max = stack->number->value;
	while (true)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (max);
}

int	find_min_int(t_stack *stack)
{
	t_number	*current;
	int			min;

	if (stack->size == 0)
		return (0);
	current = stack->number;
	min = stack->number->value;
	while (true)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (min);
}
