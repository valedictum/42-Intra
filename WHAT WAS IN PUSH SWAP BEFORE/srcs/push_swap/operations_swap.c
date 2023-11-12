/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:17:43 by atang             #+#    #+#             */
/*   Updated: 2023/11/10 21:31:22 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a, int *operation_count)
{
	int	temp;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = temp;
	}
	ft_printf("sa\n");
	(*operation_count)++;
}

/* 
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if 
there is only one or no elements.
 */

void	sb(t_stack_node **stack_b, int *operation_count)
{
	int	temp;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = temp;
	}
	ft_printf("sb\n");
	(*operation_count)++;
}

/* 
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if 
there is only one or no elements.
 */

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
	sa(stack_a, operation_count);
	sb(stack_b, operation_count);
	ft_printf("ss\n");
	(*operation_count)++;
}

/* 
ss : sa and sb at the same time.
 */
