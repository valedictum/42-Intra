/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:13:46 by atang             #+#    #+#             */
/*   Updated: 2023/06/06 11:30:16 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*orig;
	char	*dupe;
	int		i;

	orig = src;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	dupe = (char *)malloc(sizeof(char) * (len + 1));
	if (dupe == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dupe[i] = orig[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}
/*
int	main(void)
{
	char	*original;
	char	*copy;

	original = "Hello World!";
	copy = ft_strdup(original);
	if (copy != NULL)
	{
		printf("Original: %s\n", original);
		printf("Copy: %s\n", copy);
	}
	return (0);
}
*/
