/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checkers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:27:48 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:27:50 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_alpha(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == 0)
			return (false);
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
			{
				j++;
				if (!ft_isdigit(arg[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_unique(int *numbers, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (numbers[i] == numbers[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	int_len(char **pika)
{
	int	i;

	i = 0;
	while (pika[i])
		i++;
	return (i);
}

int	amount_of_numbers(char **arg)
{
	int	size;

	size = 0;
	while (arg[size])
		size++;
	return (size);
}

bool	is_it_sorted(t_stack *stack)
{
	t_number	*current;

	current = stack->number;
	while (true)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
		if (current->next == stack->number)
			break ;
	}
	return (true);
}
