/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:24:05 by atang             #+#    #+#             */
/*   Updated: 2023/09/29 18:46:56 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack_node	*ps_create_and_insert_node(t_stack_node *stack, int value)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)ps_safe_malloc(sizeof(t_stack_node));
	new_node->value = value;
	new_node->next = stack;
	return (new_node);
}
