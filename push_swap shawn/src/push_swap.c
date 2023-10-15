/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:32:22 by jlyu              #+#    #+#             */
/*   Updated: 2023/08/10 11:14:14 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static unsigned int	strtint(char *str)
{
	unsigned int	res;
	int				flag;

	res = 0;
	flag = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
		if (*str < '0' || *str > '9')
			return (2147483649);
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		else
			return (2147483649);
		str++;
	}
	if ((res > 2147483648 && flag == -1)
		|| (res > 2147483647 && flag == 1))
		return (2147483649);
	return (res);
}

void	free_linklist(t_linklist *linklist)
{
	t_stack	*header;
	t_stack	*tem;

	header = linklist->header->next;
	while (header != NULL)
	{
		tem = header->next;
		free(header);
		header = tem;
	}
	free(linklist->header);
	free(linklist);
}

static int	check_dul(t_linklist *linka)
{
	int		*contain;
	int		min;
	int		max;
	t_stack	*tem;

	min = get_extrem(linka, 0);
	max = get_extrem(linka, 1);
	contain = malloc((max - min + 2) * sizeof(int));
	if (contain == NULL)
		return (2);
	tem = linka->header->next;
	while (tem != NULL)
	{
		if (contain[tem->value - min] == 1)
		{
			free(contain);
			return (1);
		}
		contain[tem->value - min] = 1;
		tem = tem->next;
	}
	free(contain);
	return (0);
}

static int	get_data(char **data, t_linklist *linka, t_stack *tem)
{
	unsigned int	i;
	int				flag;
	t_stack			*new_node;

	while (*data)
	{
		i = strtint(*data);
		if (i == 2147483649)
			return (1);
		flag = 1;
		new_node = initial_stack();
		if (new_node == NULL)
			return (2);
		if (**data == '-')
			flag = -1;
		new_node->value = i * flag;
		linka->rear_value = new_node->value;
		linka->size++;
		tem->next = new_node;
		tem = new_node;
		data++;
	}
	return (check_dul(linka));
}

void	push_swap(char **data)
{
	t_linklist		*linka;
	t_stack			*tem;
	int				flag;

	linka = initial_linklist();
	if (linka == NULL)
		return ;
	tem = linka->header;
	flag = get_data(data, linka, tem);
	if (flag != 0)
	{
		if (flag == 1)
			ft_putstr_fd("Error\n", 2);
		free_linklist(linka);
		return ;
	}
	ps_sort(linka);
	free_linklist(linka);
}
