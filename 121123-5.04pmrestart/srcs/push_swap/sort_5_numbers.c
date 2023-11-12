/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:30:15 by atang             #+#    #+#             */
/*   Updated: 2023/11/12 19:46:29 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ps_sort_5_numbers(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    t_stack_node* current = *stack_a;
    t_stack_node* target_element;
    int target_rank = ps_stack_size(*stack_a);

    while ((current != NULL) && (current->next != NULL))
    {
        while (current != target_element)
        {
            target_element = find_element_with_rank(stack_a, target_rank);
            if (target_element == *stack_a)
            {
                pb(stack_a, stack_b, operation_count);
                target_rank--;
                current = *stack_a;
                break;
            }
	        else if (current->position <= ps_stack_size(*stack_a) / 2)
            {
                ra(stack_a, operation_count);
            }
            else
            {
                rra(stack_a, operation_count);
            }
            if (current == target_element)
            {
                break;
            }
        }
    }
    while (*stack_b != NULL)
    {
        pa(stack_a, stack_b, operation_count);
    }
}
/*
void ps_sort_5_numbers(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
{
    pb(stack_a, stack_b, operation_count);
	pb(stack_a, stack_b, operation_count);
    ps_sort_2_numbers(stack_a, operation_count);
}
*/

