/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:16:37 by sentry            #+#    #+#             */
/*   Updated: 2024/02/11 11:12:02 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack_node **stack_a, int *operation_count)
{
    if (*stack_a != NULL && (*stack_a)->next != NULL)
    {
        if ((*stack_a)->value > (*stack_a)->next->value)
        {
            sa(stack_a, operation_count);
        }
    }
}

void	sort_3(t_stack_node **stack_a, int *operation_count)
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


/*
void	sort_5(t_stack_node	**stack_a, t_stack_node	**stack_b,
		int	*operation_count)
{
	t_stack_node	*current;
	t_stack_node	*target_element;
	int				target_rank;

	current = *stack_a;
	target_element = NULL;
	target_rank = 1;
	while ((current != NULL) && target_rank <= stack_size(*stack_a))
	{
		while (current != target_element)
		{
			target_element = find_rank(stack_a, target_rank);
			if (target_element == *stack_a)
			{
				pb(stack_a, stack_b, operation_count);
				target_rank++;
				current = *stack_a;
				// TESTING FROM HERE
				if (*stack_a != NULL && (*stack_a)->next != NULL
					&& (*stack_a)->rank > (*stack_a)->next->rank)
				{
					if (*stack_b != NULL && (*stack_b)->next != NULL
						&& (*stack_b)->rank < (*stack_b)->next->rank)
						ss(stack_a, stack_b, operation_count);
					else
						sa(stack_a, operation_count);
				}
				break;
				// TO HERE
			}
			else if (current->position <= stack_size(*stack_a) / 2)
				ra(stack_a, operation_count);
			else
				rra(stack_a, operation_count);
			if (current == target_element)
				break ;
		}
	}
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b, operation_count);
	}
}
*/

void	sort_5(t_stack_node	**stack_a, t_stack_node	**stack_b,
		int	*operation_count)
{
	t_stack_node	*current;
	t_stack_node	*target_element;
	int				target_rank;

	current = *stack_a;
	target_rank = 1;
	while (target_rank <= stack_size(*stack_a))
	{
		target_element = find_rank(stack_a, target_rank);
		if (target_element == *stack_a)
		{
			pb(stack_a, stack_b, operation_count);
			target_rank++;
			current = *stack_a;
			if (*stack_a != NULL && (*stack_a)->next != NULL
				&& (*stack_a)->rank > (*stack_a)->next->rank)
			{
				if (*stack_b != NULL && (*stack_b)->next != NULL
					&& (*stack_b)->rank < (*stack_b)->next->rank)
					ss(stack_a, stack_b, operation_count);
				else
					sa(stack_a, operation_count);
			}
		}
		else if (current->position <= stack_size(*stack_a) / 2)
			ra(stack_a, operation_count);
		else
			rra(stack_a, operation_count);
		if (current == target_element)
			break ;
	}
	while (*stack_b != NULL)
		pa(stack_a, stack_b, operation_count);
}