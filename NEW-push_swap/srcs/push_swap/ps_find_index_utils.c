/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_find_index_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:02:00 by atang             #+#    #+#             */
/*   Updated: 2023/10/01 13:40:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ps_find_index(t_stack_node *stack, int number)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == number)
		{
			stack->index = i;
			return (i);
		}
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	ps_find_correct_place_in_stack_b(t_stack_node *stack_b, int nbr_to_insert)
{
	int				i;
	t_stack_node	*temp;

	i = 1;
	if (nbr_to_insert > stack_b->value && nbr_to_insert
		> ps_find_last_element(stack_b)->value)
		i = 0;
	else if (nbr_to_insert > ps_find_max_value(stack_b) || nbr_to_insert
		< ps_find_min_value(stack_b))
		i = ps_find_index(stack_b, ps_find_max_value(stack_b));
	else
	{
		temp = stack_b->next;
		while (stack_b->value < nbr_to_insert || temp->value > nbr_to_insert)
		{
			stack_b = stack_b->next;
			temp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	ps_find_correct_place_in_stack_a(t_stack_node *stack_a, int nbr_to_insert)
{
	int				i;
	t_stack_node	*temp;

	i = 1;
	if (nbr_to_insert < stack_a->value && nbr_to_insert
		> ps_find_last_element(stack_a)->value)
		i = 0;
	else if (nbr_to_insert > ps_find_max_value(stack_a) || nbr_to_insert
		< ps_find_min_value(stack_a))
		i = ps_find_index(stack_a, ps_find_min_value(stack_a));
	else
	{
		temp = stack_a->next;
		while (stack_a->value > nbr_to_insert || temp->value < nbr_to_insert)
		{
			stack_a = stack_a->next;
			temp = stack_a->next;
			i++;
		}
	}
	return (i);
}
