/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:04:13 by atang             #+#    #+#             */
/*   Updated: 2023/05/24 10:11:04 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	char	a;
	char	b;

	a = '0';
	while (a <= '9' - n)
	{
		b = a + 1;
		while (b <= '9')
		{
			ft_putchar(a);
			ft_putchar(b);
			if (n > 1 || (a != '0' && b != '1'))
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}
/*
int	main(void)
{
	ft_print_combn(2);
	return (0);
}
*/
