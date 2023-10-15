/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:07:08 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 11:48:40 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_back_utils(t_linklist *origin, t_linklist *helper)
{
	if (helper->header->next->value > origin->header->next->value)
	{
		if (sorted(origin) == 0
			|| origin->rear_value > helper->header->next->value)
		{
			rotate(origin, 'a');
			push_back_utils(origin, helper);
			return ;
		}
	}
	else if (helper->header->next->value < origin->header->next->value
		&& origin->rear_value > helper->header->next->value
		&& origin->rear_value < origin->header->next->value)
	{
		rrotate(origin, 'a');
		push_back_utils(origin, helper);
		return ;
	}
	push(origin, helper);
	ft_printf("pa\n");
}

void	push_back(t_linklist *origin, t_linklist *helper)
{
	int	index;

	while (helper->header->next != NULL)
		push_back_utils(origin, helper);
	if (sorted(origin) == 1)
		return ;
	index = get_index(origin, 0);
	move_top_utils(origin, index, 'a');
}

void	push_back_big(t_linklist *origin, t_linklist *helper)
{
	int	index;

	while (helper->header->next != NULL)
	{
		index = get_index(helper, -1);
		move_top_utils(helper, index, 'b');
		push(origin, helper);
		ft_printf("pa\n");
	}
}
