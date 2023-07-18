/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:55:43 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 15:47:18 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string ’s’ to the given file descriptor.
s: The string to output.
fd: The file descriptor on which to write. */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/* int main(void)
{
    char *s = "Hello World!";
    int fd = 1;

    ft_putstr_fd(s, fd);
	return (0);
} */