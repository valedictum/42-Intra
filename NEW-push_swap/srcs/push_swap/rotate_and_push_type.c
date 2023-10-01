/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:59:08 by atang             #+#    #+#             */
/*   Updated: 2023/10/01 18:03:26 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_use_rarb(t_stack_node **stack_a, t_stack_node **stack_b, int required_value,
	int stack_choice)
{
	if (stack_choice == 'stack_a')
	{
		while ((*stack_a)->value != required_value
			&& ps_find_correct_place_in_stack_b(*stack_b, required_value) > 0)
			rr(stack_a, stack_b);
		while ((*stack_a)->value != required_value)
			ra(stack_a);
		while (ps_find_correct_place_in_stack_b(*stack_b, required_value) > 0)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->value != required_value
			&& ps_find_correct_place_in_stack_a(*stack_a, required_value) > 0)
			rr(stack_a, stack_b);
		while ((*stack_b)->value != required_value)
			rb(stack_b);
		while (ps_find_correct_place_in_stack_a(*stack_a, required_value) > 0)
			ra(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	ps_use_rrarrb(t_stack_node **stack_a, t_stack_node **stack_b, int required_value,
	int stack_choice)
{
	if (stack_choice == 'stack_a')
	{
		while ((*stack_a)->value != required_value
			&& ps_find_correct_place_in_stack_b(*stack_b, required_value) > 0)
			rrr(stack_a, stack_b);
		while ((*stack_a)->value != required_value)
			rra(stack_a);
		while (ps_find_correct_place_in_stack_b(*stack_b, required_value) > 0)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->value != required_value
			&& ps_find_correct_place_in_stack_a(*stack_a, required_value) > 0)
			rrr(stack_a, stack_b);
		while ((*stack_b)->value != required_value)
			rrb(stack_b);
		while (ps_find_correct_place_in_stack_a(*stack_a, required_value) > 0)
			rra(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	ps_use_rrarb(t_stack_node **stack_a, t_stack_node **stack_b, int required_value,
	int stack_choice)
{
	if (stack_choice == 'stack_a')
	{
		while ((*stack_a)->value != required_value)
			rra(stack_a);
		while (ps_find_correct_place_in_stack_b(*stack_b, required_value) > 0)
			rb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while (ps_find_correct_place_in_stack_a(*stack_a, required_value) > 0)
			rra(stack_a, stack_b);
		while ((*stack_b)->value != required_value)
			rb(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}

int	ps_use_rarrb(t_stack_node **stack_a, t_stack_node **stack_b, int required_value,
	int stack_choice)
{
	if (stack_choice == 'stack_a')
	{
		while ((*stack_a)->value != required_value)
			ra(stack_a);
		while (ps_find_correct_place_in_stack_b(*stack_b, required_value) > 0)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
	else
	{
		while (ps_find_correct_place_in_stack_a(*stack_a, required_value) > 0)
			ra(stack_a);
		while ((*stack_b)->value != required_value)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
	return (-1);
}
