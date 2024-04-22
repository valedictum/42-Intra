/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:29:51 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:29:52 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*find_node_by_index(t_stack *stack, int index)
{
	t_number	*current;

	if (!stack || !stack->number)
		return (NULL);
	current = stack->number;
	while (true)
	{
		if (current->index == index)
			return (current);
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (NULL);
}

t_number	*find_node_by_value(t_stack *stack, int value)
{
	t_number	*current;

	if (!stack || !stack->number)
		return (NULL);
	current = stack->number;
	while (true)
	{
		if (current->value == value)
			return (current);
		current = current->next;
		if (current == stack->number)
			return (NULL);
	}
}

t_number	*find_target_node_b(t_stack *stack, t_number *number)
{
	t_number	*target;
	t_number	*current;

	current = stack->number;
	target = find_node_by_value(stack, stack->max_int);
	if (number->value > target->value)
		return (find_node_by_value(stack, stack->min_int));
	while (true)
	{
		if (current->value > number->value && current->value < target->value)
			target = current;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (target);
}

t_number	*find_target_node_a(t_stack *stack, t_number *number)
{
	t_number	*target;
	t_number	*current;

	current = stack->number;
	target = find_node_by_value(stack, stack->min_int);
	if (number->value < target->value)
		return (find_node_by_value(stack, stack->max_int));
	while (true)
	{
		if (current->value < number->value && current->value > target->value)
			target = current;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (target);
}
