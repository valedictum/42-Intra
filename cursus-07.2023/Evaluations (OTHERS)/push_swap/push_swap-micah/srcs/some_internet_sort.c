/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_internet_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:55:28 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 15:55:39 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_and_send_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	median_a;
	int	median_x;
	int	i;

	while (stack_a->size > 3)
	{
		median_a = calculate_a(stack_a);
		median_x = calculate_x(stack_a, median_a);
		i = stack_a->size;
		while (i-- > 0)
		{
			if (stack_a->number->value > median_a)
				run_operation(stack_a, NULL, RA);
			else
			{
				run_operation(stack_a, stack_b, PB);
				if (stack_a->number->value < median_x && stack_b->size > 1)
					run_operation(NULL, stack_b, RB);
				if (stack_a->size <= 3)
					break ;
			}
		}
	}
	reset_stack(stack_a);
	sort_three(stack_a);
}

void	some_internet_sort_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_number	*cheapest;

	cheapest = find_cheapest(stack_b);
	bring_to_top_both_b(stack_a, stack_b, cheapest->target, cheapest);
	bring_to_top(stack_a, cheapest->target->value);
	bring_to_top_b(stack_b, cheapest->value);
	run_operation(stack_a, stack_b, PA);
}

void	some_internet_sort(t_stack *stack_a, t_stack *stack_b)
{
	initialise_new_values(stack_a);
	refresh_index(stack_a);
	calculate_and_send_to_b(stack_a, stack_b);
	while (stack_b->size > 0)
	{
		reset_b(stack_a, stack_b);
		calculate_costs_b(stack_a, stack_b);
		some_internet_sort_b_to_a(stack_a, stack_b);
	}
	stack_a->min_int = find_min_int(stack_a);
	bring_to_top(stack_a, stack_a->min_int);
	refresh_index(stack_a);
}
