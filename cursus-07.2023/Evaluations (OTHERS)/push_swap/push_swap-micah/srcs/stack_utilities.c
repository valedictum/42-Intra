/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:28 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:31:30 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_stack *stack)
{
	t_number	*current;
	t_number	*prev;

	if (!stack || stack->number == NULL)
		return ;
	current = stack->number->prev;
	while (current->position != HEAD)
	{
		prev = current->prev;
		free(current);
		current = prev;
	}
	if (current)
		free(current);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free_nodes(stack_a);
	free(stack_a);
	free_nodes(stack_b);
	free(stack_b);
}

void	revert_to_head(t_stack *stack)
{
	t_number	*current;

	if (!stack || !stack->number || stack->number->position == HEAD
		|| stack->size < 2)
		return ;
	while (true)
	{
		current = stack->number;
		if (stack->number->position == HEAD)
			break ;
		current = current->next;
	}
}

void	reset_stack(t_stack *stack)
{
	if (!stack || !stack->number || stack->size == 0)
		return ;
	revert_to_head(stack);
	stack->size = find_stack_size(stack);
	stack->min_int = find_min_int(stack);
	stack->max_int = find_max_int(stack);
	refresh_index(stack);
}
