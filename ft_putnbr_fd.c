/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:32:09 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 15:42:18 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the integer ’n’ to the given file descriptor.
n: The integer to output.
fd: The file descriptor on which to write. */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
		{
			n = -(n + 1);
			ft_putnbr_fd(n / 10, fd);
			write(1, "8", 1);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	digit = n % 10 + '0';
	write (fd, &digit, 1);
}

/* int	main(void)
{
	ft_putnbr_fd(-2147485, 1);
	return (0);
} */