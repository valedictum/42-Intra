/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:29:11 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:29:12 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*find_cheapest(t_stack *stack)
{
	t_number	*current;
	t_number	*cheapest;

	if (!stack)
		return (NULL);
	current = stack->number;
	cheapest = stack->number;
	while (true)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (cheapest);
}

void	cost_move_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*cheapest;

	cheapest = find_cheapest(stack_a);
	bring_to_top_both(stack_a, stack_b, cheapest->target, cheapest);
	bring_to_top(stack_a, cheapest->value);
	bring_to_top_b(stack_b, cheapest->target->value);
	run_operation(stack_a, stack_b, PB);
}

void	cost_move_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	bring_to_top(stack_a, stack_b->number->target->value);
	run_operation(stack_a, stack_b, PA);
}

void	cost_sort(t_stack *stack_a, t_stack *stack_b)
{
	initialise_new_values(stack_a);
	run_operation(stack_a, stack_b, PB);
	run_operation(stack_a, stack_b, PB);
	while (stack_a->size > 3 && is_it_sorted(stack_a) == false)
	{
		reset_a(stack_a, stack_b);
		cost_move_a_to_b(stack_a, stack_b);
	}
	reset_stack(stack_a);
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		reset_b(stack_a, stack_b);
		cost_move_b_to_a(stack_a, stack_b);
	}
	reset_stack(stack_a);
	bring_to_top(stack_a, stack_a->min_int);
}
