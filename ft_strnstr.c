/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:07:27 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 21:11:28 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
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

