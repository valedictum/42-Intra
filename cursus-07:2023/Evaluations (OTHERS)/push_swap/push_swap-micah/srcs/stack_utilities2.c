/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:31:39 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:31:41 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_values_to_array(t_stack *stack, int *numbers)
{
	t_number	*current;
	int			i;

	i = 0;
	current = stack->number;
	while (true)
	{
		numbers[i] = current->value;
		current = current->next;
		i++;
		if (current == stack->number)
		{
			break ;
		}
	}
}

void	bubble_sort_part_one(int *bubble, t_stack *stack)
{
	int	i;
	int	j;
	int	temp;

	j = 0;
	i = 0;
	temp = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (bubble[j] < bubble[i])
			{
				temp = bubble[j];
				bubble[j] = bubble[i];
				bubble[i] = temp;
			}
			j++;
		}
		i++;
	}
}

void	bubble_sort_part_two(int *bubble, t_stack *stack)
{
	t_number	*current;
	int			i;

	current = stack->number;
	i = 0;
	while (true)
	{
		i = 0;
		while (i < stack->size)
		{
			if (current->value == bubble[i])
			{
				current->value = i + 1;
				break ;
			}
			i++;
		}
		current = current->next;
		if (current == stack->number)
			break ;
	}
}

void	initialise_new_values(t_stack *stack)
{
	int	*bubble;

	bubble = malloc(stack->size * sizeof(int));
	set_values_to_array(stack, bubble);
	bubble_sort_part_one(bubble, stack);
	bubble_sort_part_two(bubble, stack);
	free(bubble);
}

int	find_stack_size(t_stack *stack)
{
	int			count;
	t_number	*current;

	current = stack->number;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
		if (current == stack->number)
			break ;
	}
	return (count);
}
