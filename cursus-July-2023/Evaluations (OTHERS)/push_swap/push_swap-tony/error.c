/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:32:45 by tluanamn          #+#    #+#             */
/*   Updated: 2023/11/26 10:10:07 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ac(int ac)
{
	if (ac < 2)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

int	is_valid_number(const char *str)
{
	if (*str == '\0')
		return (0);
	if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		return (0);
	str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	check_valid_input(char **str, int ac, int *capacity, char ***temp)
{
	int	i;

	check_ac(ac);
	i = 0;
	if (ac == 2)
	{
		*temp = ft_split(str[1], ' ');
	}
	else
	{
		*temp = str + 1;
	}
	while ((*temp)[i])
	{
		if (!(is_valid_number((*temp)[i])))
		{
			write(1, "Error\n", 6);
			exit (0);
		}
		i++;
	}
	*capacity = i;
}

void	check_number(long num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
}

void	check_duplicate(int *arr, int capacity)
{
	int	i;
	int	j;

	i = 0;
	while (i < capacity - 1)
	{
		j = i + 1;
		while (j < capacity)
		{
			if (arr[i] == arr[j])
			{
				write(1, "Error\n", 6);
				exit (0);
			}
			j++;
		}
		i++;
	}
}
