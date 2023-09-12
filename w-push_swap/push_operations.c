/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:22:25 by atang             #+#    #+#             */
/*   Updated: 2023/09/12 15:11:23 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack_node	**stack_a, t_stack_node **stack_b)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	if (*stack_b != NULL)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (new_node == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		new_node->value = (*stack_b)->value;
		new_node->next = *stack_a;
		*stack_a = new_node;
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		free(temp);
	}
}

/* 
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
 */

void	pb(t_stack_node	**stack_b, t_stack_node **stack_a)
{
	t_stack_node	*new_node;
	t_stack_node	*temp;

	if (*stack_a != NULL)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (new_node == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		new_node->value = (*stack_a)->value;
		new_node->next = *stack_b;
		*stack_b = new_node;
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(temp);
	}
}

/* 
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
 */

