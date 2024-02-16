/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:38:12 by atang             #+#    #+#             */
/*   Updated: 2024/02/16 19:08:57 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted_descending(t_stack_node *stack_a)
{
	int	prev_value;

	prev_value = INT_MAX;
	while (stack_a)
	{
		if (prev_value < stack_a->value)
			return (0);
		prev_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}

void	chunk_sort_3(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	t_stack_node	*current;
	t_chunk_node	*chunk_head;
	t_chunk_node	*chunk_tail;
	int				max_rank;
	int				i;
	int				chunk_start;
	int				chunk_end;

	max_rank = stack_size(*stack_a);
	i = 0;
	while (i < 3)
	{
		current = *stack_a;
		set_chunk_null(&chunk_head, &chunk_tail);
		chunk_start = i * (max_rank / 3) + 1;
		if (i == 2)
			chunk_end = max_rank;
		else
			chunk_end = (i + 1) * (max_rank / 3);
		while (current != NULL && !is_sorted(*stack_a))
		{
			if (current->rank >= chunk_start && current->rank <= chunk_end)
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
	while (i < 20)
	{
		current = *stack_a;
		set_chunk_null(&chunk_head, &chunk_tail);
		while (current != NULL && !check_if_sorted_descending(*stack_a))
		{
			if (current->rank >= (i * (max_rank(*stack_a) / 20) + 1)
				&& current->rank <= ((i + 1) * (max_rank(*stack_a)
						/ 20)))
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

// OG
void	insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b,
			int *operation_count)
{
	t_stack_node	*target_element;
	int				max_rank;
	int				target_rank;

	max_rank = stack_size(*stack_b);
	target_rank = max_rank;
	while (*stack_b != NULL && target_rank >= 1)
	{
		target_element = find_rank(stack_b, target_rank);
		rotate_to_top_of_b(stack_b, target_element, operation_count);
		if (*stack_b != NULL)
		{
			pa(stack_a, stack_b, operation_count);
			update_positions(*stack_a);
			update_positions(*stack_b);
			target_rank--;
		}
	}
}
