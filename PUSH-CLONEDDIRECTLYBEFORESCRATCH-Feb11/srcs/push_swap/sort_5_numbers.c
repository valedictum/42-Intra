/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:30:15 by atang             #+#    #+#             */
/*   Updated: 2024/01/28 17:16:52 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//OG
void	ps_sort_5_numbers(t_stack_node	**stack_a, t_stack_node	**stack_b,
		int	*operation_count)
{
	t_stack_node	*current;
	t_stack_node	*target_element;
	int				target_rank;

	current = *stack_a;
	target_element = NULL;
	target_rank = 1;
	while ((current != NULL) && target_rank <= ps_stack_size(*stack_a))
	{
		while (current != target_element)
		{
			target_element = find_element_with_rank(stack_a, target_rank);
			if (target_element == *stack_a)
			{
				pb(stack_a, stack_b, operation_count);
				target_rank++;
				current = *stack_a;
				// TESTING FROM HERE
				if (*stack_a != NULL && (*stack_a)->next != NULL
					&& (*stack_a)->rank > (*stack_a)->next->rank)
				{
					if (*stack_b != NULL && (*stack_b)->next != NULL
						&& (*stack_b)->rank < (*stack_b)->next->rank)
						ss(stack_a, stack_b, operation_count);
					else
						sa(stack_a, operation_count);
				}
				break;
				// TO HERE
			}
			else if (current->position <= ps_stack_size(*stack_a) / 2)
				ra(stack_a, operation_count);
			else
				rra(stack_a, operation_count);
			if (current == target_element)
				break ;
		}
	}
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b, operation_count);
	}
}

/*
// TESTING
void	ps_sort_5_numbers(t_stack_node	**stack_a, t_stack_node	**stack_b,
		int	*operation_count)
{
	if (ps_check_if_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, operation_count);
	if (ps_check_if_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, operation_count);
	ps_sort_3_numbers(stack_a, operation_count);
	ps_sort_2_numbers(stack_b, operation_count);
	insertion_sort(stack_a, stack_b, operation_count);
}
*/
