/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:24:05 by atang             #+#    #+#             */
/*   Updated: 2023/10/06 10:50:35 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ps_create_and_insert_node(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;

	new_node = (t_stack_node *)ps_safe_malloc(sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;

	if (stack == NULL)
		return (new_node);
	current = stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (stack);
}

void	copy_stack(t_stack_node **source, t_stack_node **destination)
{
	t_stack_node	*current_source;
	t_stack_node	*tail_destination;
	t_stack_node	*new_node;

	tail_destination = NULL;
	current_source = *source;
	*destination = NULL;
	while (current_source)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (!new_node)
		{
			return ;
		}
		new_node->value = current_source->value;
		new_node->next = NULL;
		if (!*destination)
			*destination = new_node;
		else
			tail_destination->next = new_node;
		tail_destination = new_node;
		current_source = current_source->next;
	}
}
