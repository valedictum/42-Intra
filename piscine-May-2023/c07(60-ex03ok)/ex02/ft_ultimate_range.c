/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:56:32 by atang             #+#    #+#             */
/*   Updated: 2023/06/06 12:51:16 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	i = 0;
	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *)malloc((sizeof(int) * size));
	if (*range == NULL)
	{
		return (-1);
	}
	while (max > min)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (size);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	*tab = NULL;
	int	size;

	min = 3;
	max = 12;
	size = ft_ultimate_range(&tab, min, max);
	if (size == -1)
	{
		printf("Memory cannot be allocated");
		return (1);
	}
	printf("Size: %d\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", tab[i]);
	}
}
*/
