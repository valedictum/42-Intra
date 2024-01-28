/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:29:31 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:29:33 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*init_number_node(int number)
{
	t_number	*num;

	num = malloc(sizeof(t_number));
	if (!num)
		return (NULL);
	num->value = number;
	num->cost = 0;
	num->target = NULL;
	num->above_median = true;
	num->position = BODY;
	return (num);
}

void	set_many_numbers(t_stack *stack, int *numbers)
{
	int			i;
	t_number	*current;
	t_number	*first;
	t_number	*prev;

	i = -1;
	while (++i < stack->size)
	{
		current = init_number_node(numbers[i]);
		if (i == 0)
			first = current;
		else
		{
			prev->next = current;
			current->prev = prev;
		}
		if (i == stack->size - 1)
		{
			current->next = first;
			first->prev = current;
		}
		prev = current;
	}
	stack->number = first;
}

void	set_single_number(t_stack *stack, int *numbers)
{
	t_number	*current;

	current = init_number_node(numbers[0]);
	current->position = HEAD;
	current->prev = current;
	current->next = current;
	stack->number = current;
}

void	set_two_numbers(t_stack *stack, int *numbers)
{
	t_number	*first;
	t_number	*second;

	first = init_number_node(numbers[0]);
	second = init_number_node(numbers[1]);
	first->position = HEAD;
	second->position = BODY;
	first->prev = second;
	first->next = second;
	second->prev = first;
	second->next = first;
	stack->number = first;
}

void	set_numbers(t_stack *stack, int *numbers)
{
	if (stack->size == 1)
		set_single_number(stack, numbers);
	else if (stack->size == 2)
		set_two_numbers(stack, numbers);
	else
	{
		set_many_numbers(stack, numbers);
		stack->number->position = HEAD;
		stack->number->prev->position = BODY;
	}
}
