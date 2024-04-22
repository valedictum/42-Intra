/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:06 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:31:07 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*current;

	current = stack_a->number;
	while (true)
	{
		current->cost = calculate_moves_to_top(stack_a, current);
		current->cost += calculate_moves_to_top(stack_b, current->target);
		current = current->next;
		if (current == stack_a->number)
			break ;
	}
}

void	calculate_costs_b(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*current;

	current = stack_b->number;
	while (true)
	{
		current->cost = calculate_moves_to_top(stack_b, current);
		current->cost += calculate_moves_to_top(stack_a, current->target);
		current = current->next;
		if (current == stack_b->number)
			break ;
	}
}

void	t_set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*current;

	current = stack_a->number;
	while (true)
	{
		current->target = find_target_node_a(stack_b, current);
		current = current->next;
		if (current == stack_a->number)
			break ;
	}
}

void	t_set_targets_b(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*current;

	current = stack_b->number;
	while (true)
	{
		current->target = find_target_node_b(stack_a, current);
		current = current->next;
		if (current == stack_b->number)
			break ;
	}
}
