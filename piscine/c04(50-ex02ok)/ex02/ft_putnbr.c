/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:13:47 by atang             #+#    #+#             */
/*   Updated: 2023/06/03 14:23:27 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			nb = -(nb + 1);
			ft_putnbr(nb / 10);
			write(1, "8", 1);
			return ;
		}
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	digit = nb % 10 + '0';
	write (1, &digit, 1);
}
/*
int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
*/
