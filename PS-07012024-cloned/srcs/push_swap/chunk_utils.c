/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:14:50 by atang             #+#    #+#             */
/*   Updated: 2023/11/19 13:28:59 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk_node	*create_chunk_node(t_stack_node *element)
{
	t_chunk_node	*new_chunk_node;

	new_chunk_node = (t_chunk_node *)safe_malloc(sizeof(t_chunk_node));
	new_chunk_node->element = element;
	new_chunk_node->next = NULL;
	return (new_chunk_node);
}

void	set_chunk_null(t_chunk_node **chunk_head, t_chunk_node **chunk_tail)
{
	*chunk_head = NULL;
	*chunk_tail = NULL;
}

void	add_to_chunk(t_chunk_node **chunk_head, t_chunk_node **chunk_tail,
		t_stack_node *element)
{
	t_chunk_node	*chunk_node;

	chunk_node = create_chunk_node(element);
	if (*chunk_tail == NULL)
	{
		*chunk_head = chunk_node;
		*chunk_tail = chunk_node;
	}
	else
	{
		(*chunk_tail)->next = chunk_node;
		*chunk_tail = chunk_node;
	}
}

void	push_chunk_to_b(t_stack_node **stack_a, t_stack_node **stack_b,
		t_chunk_node **chunk_head, int *operation_count)
{
	t_stack_node	*chunk_element;
	t_chunk_node	*temp;

	while (*chunk_head != NULL)
	{
		chunk_element = (*chunk_head)->element;
		rotate_to_top_of_a(stack_a, chunk_element, operation_count);
		pb(stack_a, stack_b, operation_count);
		ps_update_positions(*stack_a);
		ps_update_positions(*stack_b);
		temp = *chunk_head;
		*chunk_head = (*chunk_head)->next;
		free(temp);
	}
}