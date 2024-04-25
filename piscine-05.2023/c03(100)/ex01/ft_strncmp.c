/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:43:47 by atang             #+#    #+#             */
/*   Updated: 2023/05/30 18:29:23 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		if (*s1 == '\0' && *s2 == '\0')
		{
			break ;
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str1 = "Outcome";
	char	*str2 = "Outdoor";
	unsigned int	nbr = 4;
	int	result = ft_strncmp(str1, str2, nbr);

	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
	printf("Number: %d\n", nbr);
	if (result == 0)
	{
		printf("String 1 is equal to String 2.\n");
	}
	else if (result > 0)
	{
		printf("String 1 is greater than String 2.\n");
	}
	else
	{
		printf("String 1 is less than String 2.\n");
	}
	return (0);
}
*/
