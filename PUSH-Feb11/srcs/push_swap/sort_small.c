/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 09:16:37 by sentry            #+#    #+#             */
/*   Updated: 2024/02/16 22:59:00 by sentry           ###   ########.fr       */
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

void	insert_in_order(t_stack_node **stack_a, t_stack_node **stack_b,
					int *operation_count)
{
    while (*stack_b != NULL)
    {
        int current_rank = (*stack_b)->rank;

 		if (*stack_b != NULL && (*stack_a == NULL || current_rank >= (*stack_a)->rank))
        {
            pa(stack_a, stack_b, operation_count);
        }
        // Find the correct insertion point
        while (*stack_a != NULL && current_rank > (*stack_a)->rank)
        {
            ra(stack_a, operation_count);
        }

        while (*stack_a != NULL && current_rank < (*stack_a)->rank)
        {
            rra(stack_a, operation_count);
        }
    }
}

void	sort_5(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	while (!is_sorted(*stack_a))
	{
		pb(stack_a, stack_b, operation_count);
		if (stack_size(*stack_a) == 3)
		{
			ft_printf("Now sorted 3 on A:\n");
			sort_3(stack_a, operation_count);
			ft_printf("Sorted 2 on B:\n");
			sort_2(stack_b, operation_count);
			ft_printf("Now both sorted\n");
			ft_printf("Stack A:\n");
			print_stack(*stack_a);
			ft_printf("Stack B:\n");
			print_stack(*stack_b);
			break ;
		}
	}
	while (*stack_b != NULL)
	{
		insert_in_order(stack_a, stack_b, operation_count);
	}
}