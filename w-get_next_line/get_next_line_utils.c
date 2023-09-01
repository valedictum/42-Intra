/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:49:11 by atang             #+#    #+#             */
/*   Updated: 2023/09/01 18:02:48 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	len = gnl_strlen(s1);
	str = (char *)malloc(len + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (const unsigned char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	total_len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = gnl_strlen(s1);
	len_s2 = gnl_strlen(s2);
	total_len = len_s1 + len_s2;
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	gnl_memcpy(result, s1, len_s1);
	gnl_memcpy(result + len_s1, s2, len_s2);
	result[total_len] = '\0';
	return (result);
}
