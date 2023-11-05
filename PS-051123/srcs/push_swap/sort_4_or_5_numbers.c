/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_or_5_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:30:15 by atang             #+#    #+#             */
/*   Updated: 2023/10/29 20:23:31 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ps_sort_4_or_5_numbers(t_stack_node** stack_a, t_stack_node** stack_b, int *operation_count)
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
                ft_printf("Target at top of A - Pushed %d to B (Rank %d)\n", target_element->value, target_element->rank);
                ps_update_positions(*stack_a);
                ps_update_positions(*stack_b);
                ft_printf("Stack A (top to bottom):\n");
                if (*stack_a == NULL)
                {
                    ft_printf("--Empty--\n");
                }
                ps_print_stack(*stack_a);
                ft_printf("Stack B (top to bottom):\n");
                if (*stack_b == NULL)
                {
                    ft_printf("--Empty--\n");
                }
                ps_print_stack(*stack_b);
                ft_printf("\n");
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
        ft_printf("Pushing element from B back onto A\n");
        ft_printf("\n");
    }
}