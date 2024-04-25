/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:24:31 by atang             #+#    #+#             */
/*   Updated: 2023/05/30 12:39:09 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
		{
			return (-1);
		}
		else if (s1[i] > s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str1 = "World";
	char	*str2 = "Hello";
	int	result = ft_strcmp(str1, str2);

	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
	if (result == 0)
	{
		printf("String 1 is equal to String 2.\n");
	}
	else if (result < 0)
	{
		printf("String 1 is less than String 2.\n");
	}
	else
	{
		printf("String 1 is greater than String 2.\n");
	}
	return (0);
}
*/
