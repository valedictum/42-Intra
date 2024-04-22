/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:31:35 by atang             #+#    #+#             */
/*   Updated: 2023/06/06 19:16:12 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arrints;

	if (min >= max)
	{
		return (NULL);
	}
	i = max - min;
	arrints = (int *)malloc((sizeof(int) * i));
	if (arrints == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (max > min)
	{
		arrints[i] = min;
		min++;
		i++;
	}
	return (arrints);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i;
	int	size;

	i = 0;
	min = 5;
	max = 10;
	size = max - min;
	tab = ft_range(min, max);
	while (i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}
*/
