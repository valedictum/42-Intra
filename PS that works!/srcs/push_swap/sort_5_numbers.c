/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:30:15 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 17:19:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_b != NULL && (*stack_b)->value < (*stack_a)->value)
		pa(stack_a, stack_b);
	else if (*stack_b != NULL && (*stack_b)->value > (*stack_a)->value
		&& (*stack_b)->next != NULL && (*stack_b)->value
		< (*stack_a)->next->value)
		ps_ra_then_pa_then_rra(stack_a, stack_b);
	else if (*stack_b != NULL && (*stack_b)->next != NULL && (*stack_b)->value
		> (*stack_a)->next->value)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
		rra(stack_a);
	}
	else if (*stack_b != NULL && (*stack_b)->value > (*stack_a)->next->value)
	{
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}

void	second_stack(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (*stack_b != NULL && (*stack_b)->value < (*stack_a)->value)
		pa(stack_a, stack_b);
	else if (*stack_b != NULL && (*stack_b)->value > (*stack_a)->value
		&& (*stack_b)->next != NULL && (*stack_b)->value
		< (*stack_a)->next->value)
		ps_ra_then_pa_then_rra(stack_a, stack_b);
	else if (*stack_b != NULL && (*stack_b)->next != NULL && (*stack_b)->value
		> (*stack_a)->next->value)
	{
		ra(stack_a);
		pa(stack_a, stack_b);
		sa(stack_a);
		rra(stack_a);
	}
	else if (*stack_b != NULL && (*stack_b)->next != NULL && (*stack_b)->value
		> (*stack_a)->next->next->value)
	{
		rra(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
		rotate_stack_a_radix(stack_a);
	}
	else if (*stack_b != NULL && (*stack_b)->value
		> (*stack_a)->next->next->value)
		ps_pa_then_ra(stack_a, stack_b);
}

void	ps_sort_5_numbers(t_stack_node **stack_a, t_stack_node **stack_b)
{
	pb(stack_b, stack_a);
	pb(stack_b, stack_a);
	ps_sort_3_numbers(stack_a);
	while (*stack_b != NULL)
	{
		if ((*stack_a)->next->value == 3)
			first_stack(stack_a, stack_b);
		else if ((*stack_a)->next->value == 4)
			second_stack(stack_a, stack_b);
	}
}