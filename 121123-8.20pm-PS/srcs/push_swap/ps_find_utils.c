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

t_stack_node	*ps_find_last_element(t_stack_node	*stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
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

t_stack_node	*ps_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min_node->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

/* 
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
*/

t_stack_node	*ps_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
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

t_stack_node* find_element_with_rank(t_stack_node** stack, int target_rank)
{
    t_stack_node* current = *stack;

    while (current != NULL)
    {
        if (current->rank == target_rank)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}
