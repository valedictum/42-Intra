/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:19:32 by atang             #+#    #+#             */
/*   Updated: 2023/06/04 16:34:27 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0 || nb == 1)
	{		
		return (1);
	}
	else
	{
		return (nb * ft_recursive_factorial(nb - 1));
	}
}	
/*
int	main(void)
{
	int	nb = 10;

	printf("%d", ft_recursive_factorial(nb));
	return (0);
}
*/
