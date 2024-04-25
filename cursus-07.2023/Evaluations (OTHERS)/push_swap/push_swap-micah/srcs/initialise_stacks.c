/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:29:40 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:29:41 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_a(t_stack *stack, int *numbers, int size)
{
	stack->size = size;
	set_numbers(stack, numbers);
	stack->max_int = find_max_int(stack);
	stack->min_int = find_min_int(stack);
	stack->size = find_stack_size(stack);
}

void	initialise_b(t_stack *stack)
{
	stack->number = NULL;
	stack->size = 0;
	stack->max_int = 0;
	stack->min_int = 0;
}

void	initialise_stacks(t_stack **stack_a, t_stack **stack_b, int *numbers,
		int size)
{
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	initialise_a(*stack_a, numbers, size);
	initialise_b(*stack_b);
	free(numbers);
}
