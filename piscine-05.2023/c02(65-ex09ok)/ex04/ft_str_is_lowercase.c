/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:45:28 by atang             #+#    #+#             */
/*   Updated: 2023/05/29 18:18:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/

int	ft_str_is_lowercase(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	str1[100];
	char	str2[100];
	char	str3[100];
	char	str4[100];

	strcpy(str1, "thisisonlylowercase");
	strcpy(str2, "THISISUPPERCASE");
	strcpy(str3, "This IS botH");
	strcpy(str4, "\0");
	printf("%d\n", ft_str_is_lowercase(str1));
	printf("%d\n", ft_str_is_lowercase(str2));
	printf("%d\n", ft_str_is_lowercase(str3));
	printf("%d\n", ft_str_is_lowercase(str4));
	return (0);
}
*/
