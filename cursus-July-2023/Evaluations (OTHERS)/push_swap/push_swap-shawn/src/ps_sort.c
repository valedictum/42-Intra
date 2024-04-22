/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:00:54 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 11:11:05 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ps_sort_2(t_linklist *linka)
{
	swap(linka->header->next, 'a');
	return ;
}

static void	ps_sort_3_util(t_linklist *linka, t_stack *header)
{
	if (header->value < header->next->next->value)
	{
		swap(header, 'a');
	}
	else
	{
		if (header->next->value > header->next->next->value)
		{
			swap(header, 'a');
			rrotate(linka, 'a');
		}
		else
		{
			rotate(linka, 'a');
		}
	}
}

static void	ps_sort_3(t_linklist *linka)
{
	t_stack	*header;

	header = linka->header->next;
	if (header->value > header->next->value)
		ps_sort_3_util(linka, header);
	else
	{
		if (header->value < header->next->next->value)
		{
			swap(header, 'a');
			rotate(linka, 'a');
		}
		else
		{
			rrotate(linka, 'a');
		}
	}
}

static void	ps_sort_5(t_linklist *origin, t_linklist *helper)
{
	int	index;

	if (origin->size == 3)
	{
		ps_sort(origin);
		push_back(origin, helper);
		return ;
	}
	index = get_index(origin, 1);
	move_top_utils(origin, index, 'a');
	push(helper, origin);
	ft_printf("pb\n");
	ps_sort_5(origin, helper);
}

void	ps_sort(t_linklist *linka)
{
	t_linklist	*helper;

	if (sorted(linka) == 1)
		return ;
	if (linka->size <= 2)
		ps_sort_2(linka);
	else if (linka->size == 3)
		ps_sort_3(linka);
	else
	{
		helper = initial_linklist();
		if (linka->size <= 5)
			ps_sort_5(linka, helper);
		else if (linka->size <= 100)
			ps_sort_big(linka, helper, 5);
		else if (linka->size <= 500)
			ps_sort_big(linka, helper, 12);
		else
			ps_sort_big(linka, helper, linka->size / 50);
		free_linklist(helper);
	}
}
