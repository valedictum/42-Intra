/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:31:45 by atang             #+#    #+#             */
/*   Updated: 2023/11/10 21:31:15 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_to_top_of_a(t_stack_node **stack, t_stack_node *target,
                        int *operation_count)
{
    t_stack_node *current = *stack;

    while (current != target)
    {
        if (target->position <= ps_stack_size(*stack) / 2)
            ra(stack, operation_count);
        else
            rra(stack, operation_count);
        current = *stack;
    }
}

void rotate_to_top_of_b(t_stack_node **stack, t_stack_node *target,
                        int *operation_count)
{
    t_stack_node *current = *stack;

    while (current != target)
    {
        if (target->position <= ps_stack_size(*stack) / 2)
            rb(stack, operation_count);
        else
            rrb(stack, operation_count);
        current = *stack;
    }
}
