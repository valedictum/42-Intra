/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:10:49 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 11:11:17 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_top_utils(t_linklist *origin, int index, char c)
{
	if (index == 0)
		return ;
	if (index == 1)
	{
		rotate(origin, c);
	}
	else if (index == origin->size - 1)
	{
		rrotate(origin, c);
	}
	else if (index <= origin->size / 2)
	{
		rotate(origin, c);
		move_top_utils(origin, index - 1, c);
	}
	else if (index > origin->size / 2 && index < origin->size - 1)
	{
		rrotate(origin, c);
		move_top_utils(origin, index + 1, c);
	}
}

int	get_index(t_linklist *origin, int flag)
{
	int		index_min;
	int		index_max;
	t_stack	*header;

	header = origin->header->next;
	index_min = get_extrem_index(origin, 0);
	index_max = get_extrem_index(origin, 1);
	if (flag == 0)
		return (index_min);
	if (flag == -1)
		return (index_max);
	if (index_min < (origin->size - index_min - 1))
	{
		if (index_min < index_max)
			return (index_min);
		else
			return (index_max);
	}
	else
	{
		if (index_min > index_max)
			return (index_min);
		else
			return (index_max);
	}
}
