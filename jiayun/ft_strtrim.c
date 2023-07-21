/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:45:16 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 17:59:41 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	rear;
	char	*str;

	if (!s1)
	{
		return (NULL);
	}
	str = 0;
	if (s1 != NULL && set != NULL)
	{
		front = 0;
		rear = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (rear > front && s1[rear - 1] && ft_strchr(set, s1[rear - 1]))
			rear--;
		str = (char *)malloc(sizeof(char) * (rear - front + 1));
		if (str != NULL)
			ft_strlcpy(str, &s1[front], rear - front + 1);
		return (str);
	}
	return (NULL);
}
/*
int main (void)
{
	printf("%s\n", ft_strtrim("", ""));
	printf("%s\n", ft_strtrim("abbbbbxsc", "abdc"));
}
*/
