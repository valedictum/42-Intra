/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:18:02 by atang             #+#    #+#             */
/*   Updated: 2023/11/10 21:31:22 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a, int *operation_count)
{
	t_stack_node	*last_element;
	t_stack_node	*temp;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		last_element = *stack_a;
		while (last_element->next != NULL)
			last_element = last_element->next;
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		last_element->next = temp;
	}
	ft_printf("ra\n");
	(*operation_count)++;
}

/* 
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
 */

void	rb(t_stack_node **stack_b, int *operation_count)
{
	t_stack_node	*last_element;
	t_stack_node	*temp;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		last_element = *stack_b;
		while (last_element->next != NULL)
			last_element = last_element->next;
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		last_element->next = temp;
	}
	ft_printf("rb\n");
	(*operation_count)++;
}

/* 
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
 */

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
	ra(stack_a, operation_count);
	rb(stack_b, operation_count);
	ft_printf("rr\n");
	(*operation_count)++;
}

/* 
rr : ra and rb at the same time.
 */