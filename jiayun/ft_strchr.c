/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:34:00 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 01:02:09 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == find)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == find)
	{
		return ((char *)s + i);
	}
	return (0);
}
/*
int main() 
{
    const char *str = "Hello, world!";
    int searchChar = 'o';

    char *result = ft_strchr(str, searchChar);
    if (result != NULL)
	{	
        printf("Character '%c' found at position: %ld\n", 
		searchChar, result - str);
	}
    else
	{
        printf("Character '%c' not found\n", searchChar);
	}
    return 0;
}
*/
