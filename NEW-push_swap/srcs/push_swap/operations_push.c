/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 18:46:51 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack_node	**stack_a, t_stack_node **stack_b)
{
	int				value;
	t_stack_node	*temp;

	if (*stack_b != NULL)
	{
		value = (*stack_b)->value;
		*stack_a = ps_create_and_insert_node(*stack_a, value);
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
	ft_printf("pa\n");
}

/* 
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
 */

void	pb(t_stack_node	**stack_b, t_stack_node **stack_a)
{
	int				value;
	t_stack_node	*temp;

	if (*stack_a != NULL)
	{
		value = (*stack_a)->value;
		*stack_b = ps_create_and_insert_node(*stack_b, value);
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
	ft_printf("pb\n");
}

/* 
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
 */

