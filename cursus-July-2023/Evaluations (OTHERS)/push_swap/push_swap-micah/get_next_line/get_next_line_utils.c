/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:51:01 by mickim            #+#    #+#             */
/*   Updated: 2023/06/02 16:53:08 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	pika;

	pika = 0;
	if (!str)
	{
		return (0);
	}
	while (str[pika])
	{
		pika++;
	}
	return (pika);
}

int	ft_strchr_gnl(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	return (dst);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup_gnl(const char *str)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(str);
	if (len + 1 < len)
	{
		return (NULL);
	}
	new_str = malloc((len + 1) * (sizeof(char)));
	if (!new_str)
	{
		return (NULL);
	}
	if (!str)
	{
		*new_str = '\0';
	}
	else
	{
		ft_memcpy(new_str, str, (len + 1) * sizeof(char));
	}
	return (new_str);
}
