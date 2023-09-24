/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:18:27 by atang             #+#    #+#             */
/*   Updated: 2023/09/24 18:56:56 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a)
{
	t_stack_node	*last_element;
	t_stack_node	*second_last_element;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		last_element = *stack_a;
		second_last_element = NULL;
		while (last_element->next != NULL)
		{
			second_last_element = last_element;
			last_element = last_element->next;
		}
		last_element->next = *stack_a;
		second_last_element->next = NULL;
		*stack_a = last_element;
	}
	printf("rra\n");
}

/* 
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
 */

void	rrb(t_stack_node **stack_b)
{
	t_stack_node	*last_element;
	t_stack_node	*second_last_element;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		last_element = *stack_b;
		second_last_element = NULL;
		while (last_element->next != NULL)
		{
			second_last_element = last_element;
			last_element = last_element->next;
		}
		last_element->next = *stack_b;
		second_last_element->next = NULL;
		*stack_b = last_element;
	}
}

/* 
rrb (reverse rotate b): Shift down all elements of stack b by 1. 
The last element becomes the first one.
 */

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

/* 
rrr : rra and rrb at the same time.
 */