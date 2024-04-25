/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_resets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:16 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:31:19 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_min_max(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->max_int = find_max_int(stack_a);
	stack_a->min_int = find_min_int(stack_a);
	stack_b->max_int = find_max_int(stack_b);
	stack_b->min_int = find_min_int(stack_b);
}

void	reset_a(t_stack *stack_a, t_stack *stack_b)
{
	reset_min_max(stack_a, stack_b);
	refresh_index(stack_a);
	refresh_index(stack_b);
	t_set_targets_a(stack_a, stack_b);
	calculate_costs(stack_a, stack_b);
}

void	reset_b(t_stack *stack_a, t_stack *stack_b)
{
	reset_min_max(stack_a, stack_b);
	refresh_index(stack_a);
	refresh_index(stack_b);
	t_set_targets_b(stack_a, stack_b);
}

void	refresh_index(t_stack *stack)
{
	t_number	*current;
	int			i;
	int			median;

	if (!stack || stack->size == 0)
		return ;
	current = stack->number;
	i = 0;
	median = stack->size / 2;
	while (true)
	{
		current->index = i;
		if (i++ <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		if (current == stack->number)
			break ;
	}
}
