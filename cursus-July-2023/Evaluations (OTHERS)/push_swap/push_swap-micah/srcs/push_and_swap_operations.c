/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:30:33 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:30:35 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	detach_node(t_number *detached, t_stack *stack_from)
{
	stack_from->number = detached->next;
	if (stack_from->size > 1)
	{
		detached->next->prev = detached->prev;
		detached->prev->next = detached->next;
		stack_from->number->position = HEAD;
		if (stack_from->size == 2)
		{
			stack_from->number->next = stack_from->number;
			stack_from->number->prev = stack_from->number;
			stack_from->number->position = HEAD;
		}
	}
	else
		stack_from->number = NULL;
}

void	attach_node(t_number *detached, t_stack *stack_to)
{
	if (stack_to->size > 0)
	{
		detached->next = stack_to->number;
		detached->prev = stack_to->number->prev;
		if (stack_to->size == 1)
			stack_to->number->position = HEAD;
		else
			stack_to->number->position = BODY;
		stack_to->number->prev->next = detached;
		stack_to->number->prev = detached;
	}
	else
	{
		detached->next = detached;
		detached->prev = detached;
		detached->position = HEAD;
	}
	stack_to->number = detached;
	stack_to->number->position = HEAD;
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_number	*detached;

	detached = stack_from->number;
	detach_node(detached, stack_from);
	attach_node(detached, stack_to);
	stack_from->size--;
	stack_to->size++;
}

void	swap_contents(t_number *first, t_number *second)
{
	t_number	temp;

	temp = *first;
	first->value = second->value;
	first->index = second->index;
	first->cost = second->cost;
	first->target = second->target;
	first->above_median = second->above_median;
	second->value = temp.value;
	second->index = temp.index;
	second->cost = temp.cost;
	second->target = temp.target;
	second->above_median = temp.above_median;
}

void	swap(t_stack *stack)
{
	t_number	*first;
	t_number	*second;

	if (stack->size < 2)
		return ;
	first = stack->number;
	second = first->next;
	if (first != NULL && second != NULL)
		swap_contents(first, second);
}
