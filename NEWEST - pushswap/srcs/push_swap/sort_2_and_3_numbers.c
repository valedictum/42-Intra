/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_and_3_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:22:20 by atang             #+#    #+#             */
/*   Updated: 2023/10/02 17:12:56 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_2_numbers(t_stack_node **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
		}
	}
}

void	ps_sort_3_numbers(t_stack_node **stack_a)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	if (a->value > b->value && b->value < c->value && a->value < c->value)
		sa(stack_a);
	else if (a->value > b->value && b->value > c->value && a->value > c->value)
		sa(stack_a);
	if (b->value > a->value && b->value > c->value && a->value > c->value)
		rra(stack_a);
	else if (a->value < b->value && b->value > c->value && a->value < c->value)
		sa(stack_a);
	if (a->value > b->value && b->value < c->value && a->value > c->value)
		ra(stack_a);
}
