/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:01:28 by atang             #+#    #+#             */
/*   Updated: 2023/05/29 16:01:15 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
int	ft_str_is_alpha(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
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

	strcpy(str1, "This is the alphabet");
	strcpy(str2, "Thisisthealphabet");
	strcpy(str3, "THISISthealphabet");
	strcpy(str4, "\0");
	printf("%d\n", ft_str_is_alpha(str1));
	printf("%d\n", ft_str_is_alpha(str2));
	printf("%d\n", ft_str_is_alpha(str3));
	printf("%d\n", ft_str_is_alpha(str4));
	return (0);
}
*/
