/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:27:57 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:28:50 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*numerify_argument(char **arg)
{
	int		len;
	int		i;
	int		*array;
	long	num;

	len = 0;
	i = 0;
	while (arg[len])
		len++;
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
		print_error();
	while (i < len)
	{
		num = ft_atoi(arg[i]);
		if (num > INT_MAX || INT_MIN > num)
		{
			free(array);
			print_error();
		}
		array[i] = (int)num;
		i++;
	}
	return (array);
}

void	parse_argument(char *arg, int **numbers, int *size)
{
	char	**pika;
	int		len;

	pika = ft_split(arg, ' ');
	len = int_len(pika);
	if (check_alpha(pika) == false)
	{
		free_multi_array(pika);
		print_error();
	}
	*numbers = numerify_argument(pika);
	*size = amount_of_numbers(pika);
	free_multi_array(pika);
	if (check_unique(*numbers, len) == false)
	{
		free(*numbers);
		print_error();
	}
}

void	parse_multi_arguments(char **arg, int **numbers, int *size)
{
	int	len;

	len = int_len(arg + 1);
	if (check_alpha(arg + 1) == false)
		print_error();
	*numbers = numerify_argument(arg + 1);
	*size = amount_of_numbers(arg + 1);
	if (check_unique(*numbers, len) == false)
	{
		free(*numbers);
		print_error();
	}
}
