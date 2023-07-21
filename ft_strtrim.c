/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:52:31 by atang             #+#    #+#             */
/*   Updated: 2023/07/21 12:46:34 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name
	ft_strtrim

Prototype
	char *ft_strtrim(char const *s1, char const *set);

Parameters
	s1: The string to be trimmed.
	set: The reference set of characters to trim.

Return value
	The trimmed string.
	NULL if the allocation fails.

External functs.
	malloc

Description
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
	specified in ’set’ removed from the beginning and the end of the string.
 */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*str;

	front = 0;
	back = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	back = ft_strlen(s1);
	while (back > front && ft_strchr(set, s1[back - 1]))
		back--;
	str = (char *)malloc(sizeof(char) * (back - front + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[front], back - front + 1);
	return (str);
}

/* int	main(void)
{
	printf("%s\n", ft_strtrim("investing", "ing"));
	printf("%s\n", ft_strtrim("aabbcc", "abc"));
	return (0);
}
 */