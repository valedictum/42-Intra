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

#include "../../includes/push_swap.h"

t_stack_node	*ps_find_last_element(t_stack_node	*stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ps_find_stack_size(t_stack_node	*stack)
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

int	ps_find_min_value(t_stack_node *stack)
{
	int	min_value;

	if (!stack)
		return (-1);

	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
			min_value = stack->value;
		stack = stack->next;
	}
	return (min_value);
}

int	ps_find_max_value(t_stack_node *stack)
{
	int	max_value;

	if (!stack)
		return (-1);

	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
			max_value = stack->value;
		stack = stack->next;
	}
	return (max_value);
}
