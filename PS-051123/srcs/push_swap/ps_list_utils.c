/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:24:05 by atang             #+#    #+#             */
/*   Updated: 2023/11/05 18:30:23 by atang            ###   ########.fr       */
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

void ps_stack_rank(t_stack_node *stack)
{
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
