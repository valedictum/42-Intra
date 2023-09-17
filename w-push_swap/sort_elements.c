/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:29:47 by atang             #+#    #+#             */
/*   Updated: 2023/09/17 18:18:27 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_two_elements(t_stack_node **stack_a)
{
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
		{
			sa(stack_a);
		}
	}
}

void	sort_three_elements(t_stack_node **stack_a)
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

void	sort_five_elements(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;
	t_stack_node	*d;
	t_stack_node	*e;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	d = (*stack_a)->next->next->next;
	e = (*stack_a)->next->next->next->next;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_two_elements(stack_a);
	while (stack_b != NULL && c->value > b->value)
		pa(stack_b, stack_a);
	if (stack_b != NULL && a->value > b->value)
	{
		sb(stack_a);
		pa(stack_b, stack_a);
	}
	if (stack_b != NULL)
		pa(stack_b, stack_a);
	if (a->value > b->value)
		ra(stack_a);
}

/* void	sort_five_elements(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;
	t_stack_node	*d;
	t_stack_node	*e;

	a = *stack_a;
	b = (*stack_a)->next;
	c = (*stack_a)->next->next;
	d = (*stack_a)->next->next->next;
	e = (*stack_a)->next->next->next->next;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_three_elements(stack_a);
	if (stack_b != NULL)
	{
		if (b->value > c->value)
			sb(stack_b);
		pa(stack_b, stack_a);
	}
	if (a->value > b->value)
		ra(stack_a);
	if (stack_b != NULL)
		pa(stack_b, stack_a);
	if (a->value > b->value)
		ra(stack_a);
}
 */





