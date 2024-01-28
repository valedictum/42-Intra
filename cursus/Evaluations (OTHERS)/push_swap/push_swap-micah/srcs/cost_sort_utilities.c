/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:29:19 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:29:22 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_moves_to_top(t_stack *stack, t_number *value)
{
	int	half;
	int	position;
	int	moves;

	half = stack->size / 2;
	position = value->index;
	if (position <= half)
		moves = position;
	else
		moves = stack->size - position;
	return (moves);
}

void	bring_to_top(t_stack *stack, int value)
{
	t_number	*to_find;

	to_find = find_node_by_value(stack, value);
	if (to_find)
	{
		if (to_find->index <= (stack->size / 2))
			while (stack->number != to_find)
				run_operation(stack, NULL, RA);
		else
			while (stack->number != to_find)
				run_operation(stack, NULL, RRA);
	}
}

void	bring_to_top_b(t_stack *stack, int value)
{
	t_number	*to_find;

	to_find = find_node_by_value(stack, value);
	if (to_find)
	{
		if (to_find->index <= (stack->size / 2))
			while (stack->number != to_find)
				run_operation(NULL, stack, RB);
		else
			while (stack->number != to_find)
				run_operation(NULL, stack, RRB);
	}
}

void	bring_to_top_both(t_stack *stack_a, t_stack *stack_b, t_number *target,
		t_number *candidate)
{
	if (target->above_median && candidate->above_median)
	{
		while (stack_b->number != target && stack_a->number != candidate)
			run_operation(stack_a, stack_b, RR);
	}
	else if (!target->above_median && !candidate->above_median)
	{
		while (stack_b->number != target && stack_a->number != candidate)
			run_operation(stack_a, stack_b, RRR);
	}
}

void	bring_to_top_both_b(t_stack *stack_a, t_stack *stack_b,
		t_number *target, t_number *candidate)
{
	if (target->above_median && candidate->above_median)
	{
		while (stack_a->number != target && stack_b->number != candidate)
			run_operation(stack_a, stack_b, RR);
	}
	else if (!target->above_median && !candidate->above_median)
	{
		while (stack_a->number != target && stack_b->number != candidate)
			run_operation(stack_a, stack_b, RRR);
	}
}
