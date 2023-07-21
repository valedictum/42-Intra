/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:46:35 by jong              #+#    #+#             */
/*   Updated: 2023/07/18 09:54:30 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	i;

	i = n;
	if (i < 0)
	{
		i *= -1;
		ft_putchar_fd('-', fd);
	}
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putchar_fd((i % 10 + '0'), fd);
	}
	else
	{
		ft_putchar_fd((i + '0'), fd);
	}
}
