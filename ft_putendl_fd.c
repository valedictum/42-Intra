/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:15:05 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 15:46:32 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string ’s’ to the given file descriptor followed by a newline.
s: The string to output.
fd: The file descriptor on which to write. */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(1, "\n", 1);
}

/* int main(void)
{
    char *s = "Hello World!";
    int fd = 1;

    ft_putendl_fd(s, fd);
	return (0);
} */