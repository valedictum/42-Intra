/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 15:38:12 by atang             #+#    #+#             */
/*   Updated: 2024/02/16 11:14:31 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted_descending(t_stack_node *stack_a)
{
	int	prev_value;

	prev_value = INT_MAX;
	while (stack_a)
	{
		if (prev_value > stack_a->value)
			return (0);
		prev_value = stack_a->value;
		stack_a = stack_a->next;
	}
	return (1);
}

/*
// OG
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
			if (current->rank >= (i * (max_rank(*stack_a) / 3) + 1)
				&& current->rank <= ((i + 1) * (max_rank(*stack_a) / 3)))
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
*/

void chunk_sort_3(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    t_stack_node *current;
    t_chunk_node *chunk_head;
    t_chunk_node *chunk_tail;
    int max_rank;
    int i;

    max_rank = stack_size(*stack_a);
    i = 0;

    while (i < 3)
    {
        current = *stack_a;
        set_chunk_null(&chunk_head, &chunk_tail);

        int chunk_start = i * (max_rank / 3) + 1;
        int chunk_end;

        if (i == 2)
        {
            chunk_end = max_rank;
        }
        else
        {
            chunk_end = (i + 1) * (max_rank / 3);
        }

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
            return;
    }
}

void chunk_sort_500(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    if (is_sorted(*stack_a))
        return;

    t_stack_node *current;
    t_chunk_node *chunk_head;
    t_chunk_node *chunk_tail;
    int max_rank;
    int i;

    max_rank = stack_size(*stack_a);
    i = 0;

    while (i < 4)
    {
        current = *stack_a;
        set_chunk_null(&chunk_head, &chunk_tail);

        int chunk_start = i * (max_rank / 4) + 1;
        int chunk_end;
        if (i == 1)
        {
            chunk_end = max_rank;
        }
        else
        {
            chunk_end = (i + 1) * (max_rank / 4);
        }

        while (current != NULL)
        {
            int currentRank = current->rank;
            if (currentRank >= chunk_start && currentRank <= chunk_end)
                add_to_chunk(&chunk_head, &chunk_tail, current);
            current = current->next;
        }

        if (chunk_head != NULL)
        {
            push_chunk_to_b(stack_a, stack_b, &chunk_head, operation_count);
            i++;
        }
        else
            return;
    }
}

/*
// OG
void	insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b,
			int	*operation_count)
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
	while (!check_if_sorted_descending(*stack_a))
	{
		ra(stack_a, operation_count);
	}
}
*/

void insertion_sort(t_stack_node **stack_a, t_stack_node **stack_b, int *operation_count)
{
    t_stack_node *target_element;
    int max_rank;
    int target_rank;

    max_rank = stack_size(*stack_b);
    target_rank = 1; // Set target_rank to 1 for ascending order
    while (*stack_b != NULL && target_rank <= max_rank)
    {
        target_element = find_rank(stack_b, target_rank);
        rotate_to_top_of_b(stack_b, target_element, operation_count);
        if (*stack_b != NULL)
        {
            pa(stack_a, stack_b, operation_count);
            update_positions(*stack_a);
            update_positions(*stack_b);
            target_rank++;
        }
    }
}
