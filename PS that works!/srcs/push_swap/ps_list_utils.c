/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:24:05 by atang             #+#    #+#             */
/*   Updated: 2023/10/20 11:34:17 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *ps_create_and_insert_node(t_stack_node *stack, int value)
{
    t_stack_node 	*new_node;
    t_stack_node 	*current;
	int				position;
    
    new_node = (t_stack_node *)ps_safe_malloc(sizeof(t_stack_node));
    new_node->value = value;
    new_node->next = NULL;
    new_node->position = 0;
    if (stack == NULL)
    {
        new_node->position = 1;
        return new_node;
    }
    current = stack;
    position = 1;
    while (current->next != NULL)
    {
        position++;
        current = current->next;
    }
    new_node->position = position + 1;
    current->next = new_node;
    return (stack);
}

void ps_stack_rank(t_stack_node *stack) {
    t_stack_node *current = stack;
    int rank = 1;

    while (current != NULL) {
        t_stack_node *temp = stack;
        int current_value = current->value;
        while (temp != NULL) {
            if (temp->value < current_value) {
                rank++;
            }
            temp = temp->next;
        }
        current->rank = rank;
        rank = 1;  // Reset rank for the next node
        current = current->next;
    }
}






/*
SECOND NEWEST
t_stack_node	*ps_create_and_insert_node(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;
	t_stack_node	*current;
	t_stack_node	*previous;

	new_node = (t_stack_node *)ps_safe_malloc(sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = NULL;
	new_node->rank = 0;

	if (stack == NULL)
	{
		new_node->rank = 1;
		return (new_node);
	}
	current = stack;
	previous = NULL;
	while (current != NULL)
	{
		if (current->value <= value)
		{
			previous = current;
			current = current->next;
			new_node->rank++;
		}
		else
		{
			break;
		}
	}
    if (previous == NULL)
    {
        new_node->rank = 1;
        new_node->next = stack;
        return (new_node);
    }
    previous->next = new_node;
    new_node->next = current;
	return (stack);
} */

/* 
//THUGGONAUT VERSION
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

//THUGGONAUT VERSION
void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
*/

/* 
PROSSI METHOD
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
 */