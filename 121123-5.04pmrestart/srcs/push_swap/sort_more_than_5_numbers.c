/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_5_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:28:54 by atang             #+#    #+#             */
/*   Updated: 2023/11/12 19:45:54 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort_3(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	t_stack_node	*current;
	t_chunk_node	*chunk_head;
	t_chunk_node	*chunk_tail;
	int				i;

	i = 0;
	while (i < 3)
	{
		current = *stack_a;
		set_chunk_null(&chunk_head, &chunk_tail);
		while (current != NULL && !is_sorted(*stack_a))
		{
			if (current->rank >= (i * (get_max_rank(*stack_a) / 3) + 1)
				&& current->rank <= ((i + 1) * (get_max_rank(*stack_a) / 3)))
				add_to_chunk(&chunk_head, &chunk_tail, current);
			current = current->next;
		}
		if (chunk_head != NULL)
		{
			push_chunk_to_b(stack_a, stack_b, &chunk_head, operation_count);
			i++;
		}
		else
			return ;
	}
}

void	chunk_sort_4(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	t_stack_node	*current;
	t_chunk_node	*chunk_head;
	t_chunk_node	*chunk_tail;
	int				i;

	i = 0;
	while (i < 4)
	{
		current = *stack_a;
		set_chunk_null(&chunk_head, &chunk_tail);
		while (current != NULL && !is_sorted(*stack_a))
		{
			if (current->rank >= (i * (get_max_rank(*stack_a) / 4) + 1)
				&& current->rank <= ((i + 1) * (get_max_rank(*stack_a) / 4)))
				add_to_chunk(&chunk_head, &chunk_tail, current);
			current = current->next;
		}
		if (chunk_head != NULL)
		{
			push_chunk_to_b(stack_a, stack_b, &chunk_head, operation_count);
			i++;
		}
		else
			return ;
	}
}

void	chunk_sort_100(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	t_stack_node	*current;
	t_chunk_node	*chunk_head;
	t_chunk_node	*chunk_tail;
	int				i;

	i = 0;
	while (i < 5)
	{
		current = *stack_a;
		set_chunk_null(&chunk_head, &chunk_tail);
		while (current != NULL && !is_sorted(*stack_a))
		{
			if (current->rank >= (i * (get_max_rank(*stack_a) / 5) + 1)
				&& current->rank <= ((i + 1) * (get_max_rank(*stack_a) / 5)))
				add_to_chunk(&chunk_head, &chunk_tail, current);
			current = current->next;
		}
		if (chunk_head != NULL)
		{
			push_chunk_to_b(stack_a, stack_b, &chunk_head, operation_count);
			i++;
		}
		else
			return ;
	}
}

void	chunk_sort_500(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	t_stack_node	*current;
	t_chunk_node	*chunk_head;
	t_chunk_node	*chunk_tail;
	int				i;

	i = 0;
	while (i < 10)
	{
		current = *stack_a;
		set_chunk_null(&chunk_head, &chunk_tail);
		while (current != NULL && !is_sorted(*stack_a))
		{
			if (current->rank >= (i * (get_max_rank(*stack_a) / 10) + 1)
				&& current->rank <= ((i + 1) * (get_max_rank(*stack_a) / 10)))
				add_to_chunk(&chunk_head, &chunk_tail, current);
			current = current->next;
		}
		if (chunk_head != NULL)
		{
			push_chunk_to_b(stack_a, stack_b, &chunk_head, operation_count);
			i++;
		}
		else
			return ;
	}
}

void insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b,
                    int *operation_count)
{
    t_stack_node *target_element;
    int max_rank;
    int target_rank;

    max_rank = ps_stack_size(*stack_b);
    target_rank = max_rank;

    while (*stack_b != NULL && target_rank >= 1)
    {
        target_element = find_element_with_rank(stack_b, target_rank);
        rotate_to_top_of_b(stack_b, target_element, operation_count);
      	if (*stack_b != NULL)
		{
			pa(stack_a, stack_b, operation_count);
			ps_update_positions(*stack_a);
			ps_update_positions(*stack_b);
			target_rank--;
		}
    }
    while (!ps_check_if_sorted_descending(*stack_a))
    {
        ra(stack_a, operation_count);
    }
}


/*
// WORKING BUT BACKWARDS
void	insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b,
		int *operation_count)
{
	t_stack_node	*target_element;
	int				max_rank;
	int				target_rank;

	max_rank = ps_stack_size(*stack_b);
	target_rank = 1;
	while (*stack_b != NULL && target_rank <= max_rank)
	{
		target_element = find_element_with_rank(stack_b, target_rank);
		rotate_to_top_of_b(stack_b, target_element, operation_count);
		if (*stack_b != NULL)
		{
			pa(stack_a, stack_b, operation_count);
			ps_update_positions(*stack_a);
			ps_update_positions(*stack_b);
			target_rank++;
		}
	}
	while (!ps_check_if_sorted(*stack_a))
	{
		ra(stack_a, operation_count);
	}
}
*/