/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 21:17:23 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 00:57:38 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occur;
	char	find;
	size_t	i;

	last_occur = (char *)s;
	find = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (last_occur[i] == find)
		{
			return (last_occur + i);
		}
		i--;
	}
	if (last_occur[i] == find)
	{
		return (last_occur);
	}
	return (NULL);
}
/*
int main() {
    const char *str = "Hello, world!";
    int searchChar = 'o';

    char *result = ft_strrchr(str, searchChar);

    if (result != NULL) {
        printf("Character '%c' last found at position: %ld\n", 
				searchChar, result - str);
    } else {
        printf("Character '%c' not found\n", searchChar);
    }
    return 0;
}
*/
