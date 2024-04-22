/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:38:44 by atang             #+#    #+#             */
/*   Updated: 2023/06/04 17:34:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
	{
		return (0);
	}
	else if (i == 0 || i == 1)
	{		
		return (1);
	}
	while (i >= 2)
	{
		i--;
		nb = nb * i;
	}
	return (nb);
}
/*
int main()
{
	int nb = 10;
	printf("%d", ft_iterative_factorial(nb));
	return (0);
}
*/
