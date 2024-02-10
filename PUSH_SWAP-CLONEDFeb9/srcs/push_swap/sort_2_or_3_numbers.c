/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_or_3_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:22:20 by atang             #+#    #+#             */
/*   Updated: 2024/02/10 16:05:04 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_2_numbers(t_stack_node **stack_a, int *operation_count)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a, operation_count);
		}
	}
}

/*
//OG
void	ps_sort_3_numbers(t_stack_node **stack_a, int *operation_count)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	if (a->value > b->value && b->value < c->value && a->value < c->value)
		sa(stack_a, operation_count);
	else if (a->value > b->value && b->value > c->value && a->value > c->value)
		sa(stack_a, operation_count);
	if (b->value > a->value && b->value > c->value && a->value > c->value)
		rra(stack_a, operation_count);
	else if (a->value < b->value && b->value > c->value && a->value < c->value)
		sa(stack_a, operation_count);
	if (a->value > b->value && b->value < c->value && a->value > c->value)
		ra(stack_a, operation_count);
}
*/

void ps_sort_3_numbers(t_stack_node **stack_a, int *operation_count)
{
    t_stack_node *a;
    t_stack_node *b;
    t_stack_node *c;

	
	if (*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
		return;
    a = *stack_a;
    b = (*stack_a)->next;
    c = (*stack_a)->next->next;
    if (a->value > b->value && b->value > c->value)
    {
        sa(stack_a, operation_count);
        rra(stack_a, operation_count);
    }
    else if (a->value > b->value && b->value < c->value && a->value < c->value)
    {
        sa(stack_a, operation_count);
    }
    else if (a->value > b->value && b->value > c->value && a->value > c->value)
    {
        rra(stack_a, operation_count);
    }
    else if (a->value < b->value && b->value > c->value && a->value < c->value)
    {
        ra(stack_a, operation_count);
    }
    else if (a->value < b->value && b->value > c->value && a->value > c->value)
    {
        sa(stack_a, operation_count);
        ra(stack_a, operation_count);
    }
}
