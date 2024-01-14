/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:31:51 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 10:53:00 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ps_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ps_stack_size(t_stack_node	*stack)
{
	size_t	stack_size;

	stack_size = 0;
	while (stack)
	{
		stack = stack->next;
		stack_size++;
	}
	return (stack_size);
}

int	get_max_rank(t_stack_node *stack)
{
	int	max_rank;

	if (!stack)
		return (-1);

	max_rank = stack->rank;
	while (stack)
	{
		if (stack->rank > max_rank)
			max_rank = stack->rank;
		stack = stack->next;
	}
	return (max_rank);
}

t_stack_node	*find_element_with_rank(t_stack_node **stack, int target_rank)
{
	t_stack_node	*current;

	current = *stack;
	while (current != NULL)
	{
		if (current->rank == target_rank)
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}
