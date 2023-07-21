/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:24:34 by atang             #+#    #+#             */
/*   Updated: 2023/07/20 16:47:27 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     memchr -- locate byte in byte string

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>

     void *
     memchr(const void *s, int c, size_t n);

DESCRIPTION
     The memchr() function locates the first occurrence of c (converted to 
	 an unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, or NULL if 
	 no such byte exists within n bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		target;
	size_t				i;

	p = s;
	i = 0;
	target = (unsigned char)c;
	while (i < n)
	{
		if (p[i] == target)
		{
			return ((void *)(p + i));
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	buffer[] = "Congratulations!";
	char	ch = 't';
	char	*result = ft_memchr(buffer, ch, ft_strlen(buffer));

	printf("String: %s\n", buffer);
	if (result != NULL)
		printf("Found '%c' at position %ld\n", ch, result - buffer);
	else
		printf("Character not found.\n");
	return (0);
} */
