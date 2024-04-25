/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:24:50 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 10:45:39 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*initial_stack(void)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	return (node);
}

t_linklist	*initial_linklist(void)
{
	t_linklist		*linka;

	linka = malloc(sizeof(t_linklist));
	if (linka == NULL)
		return (NULL);
	linka->header = initial_stack();
	if (linka->header == NULL)
		return (NULL);
	linka->size = 0;
	linka->rear_value = 0;
	return (linka);
}

int	sorted(t_linklist *linklist)
{
	t_stack	*header;

	header = linklist->header->next;
	while (header != NULL && header->next != NULL)
	{
		if (header->value > header->next->value)
			return (0);
		header = header->next;
	}
	return (1);
}

int	get_extrem(t_linklist *origin, int flag)
{
	int		min;
	int		max;
	t_stack	*header;

	header = origin->header->next;
	min = header->value;
	max = header->value;
	while (header != NULL)
	{
		if (min > header->value)
		{
			min = header->value;
		}
		if (max < header->value)
		{
			max = header->value;
		}
		header = header->next;
	}
	if (flag == 0)
		return (min);
	return (max);
}

int	get_extrem_index(t_linklist *origin, int flag)
{
	int		extrm;
	int		index;
	int		index_extrm;
	t_stack	*header;

	header = origin->header->next;
	extrm = header->value;
	index = 0;
	index_extrm = 0;
	while (header != NULL)
	{
		if (flag == 0 && extrm > header->value)
		{
			extrm = header->value;
			index_extrm = index;
		}
		if (flag == 1 && extrm < header->value)
		{
			extrm = header->value;
			index_extrm = index;
		}
		header = header->next;
		index++;
	}
	return (index_extrm);
}
