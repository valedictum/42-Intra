/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 01:58:22 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 17:31:02 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*dup_str;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	dup_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup_str)
		return (NULL);
	while (s1[i])
	{
		dup_str[i] = s1[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
/*
int main(void)
{
	char *ori_str = "Hello, world!";
	char *dup_str = ft_strdup(ori_str);

	if (dup_str != NULL)
	{
		printf("Duplicate string: %s\n", dup_str);

		free (dup_str);
	}
	return (0);
}
*/
