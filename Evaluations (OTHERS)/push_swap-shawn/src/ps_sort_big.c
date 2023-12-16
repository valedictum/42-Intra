/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:56:09 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 14:03:05 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	copy_contain(t_linklist *origin, int *contain, int min)
{
	t_stack	*header;

	header = origin->header->next;
	while (header != NULL)
	{
		contain[header->value - min] = 1;
		header = header->next;
	}
}

static void	get_tem_index(int *tem)
{
	int	index;
	int	t_index;

	index = 0;
	t_index = 0;
	while (tem[t_index] != '\0')
	{
		if (tem[t_index] != -1)
		{
			tem[t_index] = index;
			index++;
		}
		t_index++;
	}
}

static int	*pre_sort(t_linklist *origin)
{
	int	min;
	int	max;
	int	*tem;
	int	i;

	min = get_extrem(origin, 0);
	max = get_extrem(origin, 1);
	tem = malloc((max - min + 2) * sizeof(int));
	if (tem == NULL)
		return (NULL);
	i = 0;
	while (i < max - min + 2)
	{
		tem[i] = -1;
		i++;
	}
	tem[i] = '\0';
	copy_contain(origin, tem, min);
	get_tem_index(tem);
	return (tem);
}

void	ps_sort_big(t_linklist *origin, t_linklist *helper, int chunks)
{
	int	*contain;
	int	*memo;

	memo = malloc(3 * sizeof(int));
	if (memo == NULL)
		return ;
	memo[0] = get_extrem(origin, 0);
	contain = pre_sort(origin);
	if (contain == NULL)
		return ;
	memo[1] = origin->size / chunks;
	memo[2] = chunks;
	ps_sort_big_util(origin, helper, contain, memo);
	push_back_big(origin, helper);
	free(contain);
	free(memo);
}
