/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:15:02 by atang             #+#    #+#             */
/*   Updated: 2023/06/05 16:39:15 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0 && nb != 0)
	{
		return (0);
	}
	else if (((power == 0) && (nb == 0)) || (nb == 1))
	{
		return (1);
	}
	else if (nb == 0 && power == 1)
	{
		return (0);
	}
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
/*
int	main(void)
{
	int	nb = -3;
	int	power = 10;

	printf("%d", ft_iterative_power(nb, power));
	return (0);
}
*/
