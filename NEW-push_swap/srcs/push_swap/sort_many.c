/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:29:47 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 14:40:39 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"



void	ps_sort(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				i;

	stack_b = NULL;
	if (ps_find_stack_size(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = ps_sort_b(stack_a);
		stack_a = ps_sort_a(stack_a, &stack_b);
		i = ps_find_index(*stack_a, ps_find_min_value(*stack_a));
		if (i < ps_find_stack_size(*stack_a) - i)
		{
			while ((*stack_a)->value != ps_find_min_value(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack)->value != ps_find_min_value(*stack_a))
				rra(stack_a);
		}
	}
}
