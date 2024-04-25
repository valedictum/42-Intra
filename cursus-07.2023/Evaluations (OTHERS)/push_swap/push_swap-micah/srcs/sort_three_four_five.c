/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_four_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:55 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:30:57 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->number->value;
	b = stack->number->next->value;
	c = stack->number->prev->value;
	if (is_it_sorted(stack))
		return ;
	if (a == stack->max_int)
	{
		run_operation(stack, NULL, RA);
		if (b > c)
			run_operation(stack, NULL, SA);
	}
	else
	{
		if (c != stack->max_int)
			run_operation(stack, NULL, RRA);
		if (c > a || c == stack->max_int)
			run_operation(stack, NULL, SA);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	bring_to_top(stack_a, stack_a->min_int);
	run_operation(stack_a, stack_b, PB);
	sort_three(stack_a);
	run_operation(stack_a, stack_b, PA);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	bring_to_top(stack_a, stack_a->min_int);
	run_operation(stack_a, stack_b, PB);
	stack_a->min_int = find_min_int(stack_a);
	bring_to_top(stack_a, stack_a->min_int);
	run_operation(stack_a, stack_b, PB);
	sort_three(stack_a);
	run_operation(stack_a, stack_b, PA);
	run_operation(stack_a, stack_b, PA);
}
