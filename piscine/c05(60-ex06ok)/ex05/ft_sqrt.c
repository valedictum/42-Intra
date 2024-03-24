/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:16:09 by atang             #+#    #+#             */
/*   Updated: 2023/06/05 16:33:34 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include<stdio.h>
#include<limits.h>
*/
int	ft_sqrt(int nb)
{
	int	index;

	index = 1;
	if (nb <= 0)
	{
		return (0);
	}
	while (index <= 46340)
	{
		if (index * index == nb)
		{
			return (index);
		}
		index++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("The square root of %d is %d\n", INT_MAX, ft_sqrt(INT_MAX));
	printf("The square root of %d is %d\n", INT_MIN, ft_sqrt(INT_MIN));
	printf("The square root of %d is %d\n", 2147395600, ft_sqrt(2147395600));
	printf("The square root of %d is %d\n", 49, ft_sqrt(49));
	printf("The square root of %d is %d\n", 0, ft_sqrt(0));
	return (0);
}
*/
