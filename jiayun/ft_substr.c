/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 02:32:04 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 02:07:24 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub;

	size = ft_strlen(s);
	if (len > size)
		len = size;
	if (start > size)
		len = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] && size > start)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int main(void)
{
	char *str;

	str = ft_substr("Hello, 42Adelaide!", 7, 2);
	printf("%s\n", str);

	return (0);
}
*/
