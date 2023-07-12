/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:35:31 by atang             #+#    #+#             */
/*   Updated: 2023/07/12 17:59:52 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

int	main(void)
{
	const char	*str1 = "Outcome";
	const char	*str2 = "Outdoor";
	size_t	nbr = 4;
	int	result = ft_strncmp(str1, str2, nbr);

	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
	printf("Number: %zu\n", nbr);
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
