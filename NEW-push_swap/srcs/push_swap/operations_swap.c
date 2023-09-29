/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:17:43 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 14:33:32 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack_node **stack_a)
{
	int	temp;

	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->value;
		(*stack_a)->value = (*stack_a)->next->value;
		(*stack_a)->next->value = temp;
	}
	ft_printf("sa\n");
}

/* 
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if 
there is only one or no elements.
 */

void	sb(t_stack_node **stack_b)
{
	int	temp;

	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->value;
		(*stack_b)->value = (*stack_b)->next->value;
		(*stack_b)->next->value = temp;
	}
	ft_printf("sb\n");
}

/* 
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if 
there is only one or no elements.
 */

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}

/* 
ss : sa and sb at the same time.
 */
