/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:46:07 by jong              #+#    #+#             */
/*   Updated: 2023/07/17 00:11:31 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main() {
    char str[] = "Hello, world!";
    char searchChar = 'o';
    size_t searchLength = strlen(str);

    void *result = ft_memchr(str, searchChar, searchLength);

    if (result != NULL) {
        printf("Character '%c' found at position: %ld\n", 
		searchChar, (char *)result - str);
    } else {
        printf("Character '%c' not found\n", searchChar);
    }

    return 0;
}
*/
