/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:25:42 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 17:39:30 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
#include <string.h>
char *strrchr(const char *s, int c);

DESCRIPTION
The strchr() function locates the first occurrence of c (converted to a char) 
in the string pointed to by s.  The terminating null character is considered to 
be part of the string; therefore if c is `\0', the functions locate the 
terminating `\0'.
The strrchr() function is identical to strchr(), except it locates the last
occurrence of c.

RETURN VALUES
The functions strchr() and strrchr() return a pointer to the located character, 
or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return ((char *)last);
}

/* int main(void)
{
	const char *str = "Hello, World!";
	char ch = 'l';
	char *ptr = ft_strrchr(str, ch);

	printf("%s\n", str);
    if (ptr != NULL) {
        printf("Last character '%c' found at position: %ld\n", *ptr, ptr - str + 1);
    } else {
        printf("Character '%c' not found\n", ch);
    }
    return (0);
} */
