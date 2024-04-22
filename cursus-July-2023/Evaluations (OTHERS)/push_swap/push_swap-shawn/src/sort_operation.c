/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:00:57 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/09 10:44:19 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *node, char c)
{
	int	tem;

	tem = node->value;
	node->value = node->next->value;
	node->next->value = tem;
	ft_printf("s%c\n", c);
}

void	push(t_linklist *linklist, t_linklist *sourcelist)
{
	t_stack	*new_node;
	t_stack	*tem;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->value = sourcelist->header->next->value;
	new_node->next = linklist->header->next;
	linklist->header->next = new_node;
	linklist->size++;
	tem = sourcelist->header->next->next;
	free(sourcelist->header->next);
	sourcelist->header->next = tem;
	sourcelist->size--;
}

void	rotate(t_linklist *linklist, char c)
{
	t_stack	*node;
	t_stack	*new_node;
	t_stack	*tem;

	node = linklist->header->next;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->value = node->value;
	linklist->rear_value = new_node->value;
	linklist->header->next = linklist->header->next->next;
	tem = node->next;
	free(node);
	while (tem->next != NULL)
		tem = tem->next;
	tem->next = new_node;
	new_node->next = NULL;
	ft_printf("r%c\n", c);
}

void	rrotate(t_linklist *linklist, char c)
{
	t_stack	*new_node;
	t_stack	*tem;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = linklist->header->next;
	tem = new_node;
	while (tem->next->next != NULL)
		tem = tem->next;
	new_node->value = tem->next->value;
	free(tem->next);
	tem->next = NULL;
	linklist->rear_value = tem->value;
	linklist->header->next = new_node;
	ft_printf("rr%c\n", c);
}
