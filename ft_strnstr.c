/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:07:27 by atang             #+#    #+#             */
/*   Updated: 2023/07/20 16:55:54 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
NAME
     strnstr -- locate a substring in a string

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>
     char *
     strnstr(const char *haystack, const char *needle, size_t len);

DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated 
	 string needle in the string haystack, where not more than len characters 
	 are searched.  Characters that appear after a `\0' character are not 
	 searched.  Since the strnstr() function is a FreeBSD specific API, it
     should only be used when portability is not a concern.

RETURN VALUES
     If needle is an empty string, haystack is returned; if needle occurs 
	 nowhere in haystack, NULL is returned; otherwise a pointer to the first 
	 character of the first occurrence of needle is returned.
 */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	if (needle_len > len)
		return (NULL);
	while (*haystack && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/* int main(void)
{
    char haystack[] = "Hello, World!";
    char needle[] = "orl";
    size_t len = sizeof(haystack) - 1;

    char *result = ft_strnstr(haystack, needle, len);

    printf("Haystack: %s\n", haystack);
    printf("Needle: %s\n", needle);
    if (result != NULL)
    {
        printf("Substring found at index: %ld\n", result - haystack);
    }
    else
    {
        printf("Substring not found.\n");
    }
    return (0);
} */