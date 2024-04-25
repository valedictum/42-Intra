/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:34:29 by atang             #+#    #+#             */
/*   Updated: 2023/06/05 11:50:49 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0 && nb != 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	else if (nb == 0 && power == 1)
	{
		return (0);
	}
	else
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
}
/*
int	main(void)
{
	int	nb = 0;
	int	power = 0;

	printf("%d", ft_recursive_power(nb, power));
	return (0);
}
*/
