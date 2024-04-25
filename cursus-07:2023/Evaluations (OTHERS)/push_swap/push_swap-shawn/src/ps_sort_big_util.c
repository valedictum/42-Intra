/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:03:59 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 14:04:01 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_index_l(t_linklist *origin, int *contain, int k, int *memo)
{
	int		index;
	t_stack	*header;

	index = 0;
	header = origin->header->next;
	while (header != NULL)
	{
		if (contain[header->value - memo[0]] < k * memo[1]
			&& contain[header->value - memo[0]] >= (k - 1) * memo[1])
			break ;
		index++;
		header = header->next;
	}
	return (index);
}

static int	get_index_r(t_linklist *origin, int *contain, int k, int *memo)
{
	int		index;
	int		index_r;
	t_stack	*header;

	index = 0;
	header = origin->header->next;
	index_r = 0;
	while (header != NULL)
	{
		if (contain[header->value - memo[0]] < k * memo[1]
			&& contain[header->value - memo[0]] >= (k - 1) * memo[1])
		{
			index_r = index;
		}
		index++;
		header = header->next;
	}
	return (index_r);
}

static int	get_big_index(t_linklist *origin, int *contain, int k, int *memo)
{
	t_stack	*header;
	int		index_l;
	int		index_r;

	header = origin->header->next;
	index_l = get_index_l(origin, contain, k, memo);
	index_r = get_index_r(origin, contain, k, memo);
	if (index_l < origin->size - 1 - index_r)
		return (index_l);
	return (index_r);
}

void	ps_sort_big_util(t_linklist *origin, t_linklist *helper,
	int *contain, int *memo)
{
	int	j;
	int	k;
	int	index;

	k = 1;
	while (origin->header->next != NULL && k <= memo[2] + 1)
	{
		j = 0;
		while (j < (memo[1]) && origin->header->next != NULL)
		{
			index = get_big_index(origin, contain, k, memo);
			move_top_utils(origin, index, 'a');
			push(helper, origin);
			ft_printf("pb\n");
			j++;
		}
		k++;
	}
}
