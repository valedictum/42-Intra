/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:43:44 by atang             #+#    #+#             */
/*   Updated: 2023/06/07 10:34:20 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stddef.h>
*/
char	*ft_strstr(char *str, char *to_find)
{
	char	*s_ptr;
	char	*f_ptr;

	s_ptr = str;
	f_ptr = to_find;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		s_ptr = str;
		f_ptr = to_find;
		while (*f_ptr && *s_ptr && *f_ptr == *s_ptr)
		{
			f_ptr++;
			s_ptr++;
		}
		if (*f_ptr == '\0')
		{
			return (str);
		}
		str++;
	}
	return (0);
}
/*
int	main(void)
{
	char	haystack[] = "Hello, World!";
	char	needle[] = "orl";
	char	*result = ft_strstr(haystack, needle);

	printf("Haystack: %s\n", haystack);
	printf("Needle: %s\n", needle);
	if (result != 0)
	{
		printf("Substring at index: %ld\n", result - haystack);
	}
	else
	{
		printf("Substring not found.\n");
	}
	return (0);
}
*/
