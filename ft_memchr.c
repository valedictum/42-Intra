/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:24:34 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 16:25:00 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_memchr.c
#include <string.h>
void *memchr(const void *s, int c, size_t n);

DESCRIPTION
The memchr() function locates the first occurrence of c (converted to an
unsigned char) in string s.

RETURN VALUES
The memchr() function returns a pointer to the byte located, or NULL if
no such byte exists within n bytes.
*/

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *p = s;
    unsigned char target = (unsigned char)c;

    for (size_t i = 0; i < n; i++)
    {
        if (p[i] == target)
        {
            return (void *)(p + i);
        }
    }
    return (NULL);
}

int main()
{
    char buffer[] = "Hello World!";
    char ch = 'W'
    char *result = ft_memchr(buffer, ch, strlen(buffer));

    if (result != NULL)
    {
        printf("Found '%c' at position %ld\n", ch, result - buffer);
    }
    else
    {
        printf("Character not found.\n");
    }
    return (0);
}
