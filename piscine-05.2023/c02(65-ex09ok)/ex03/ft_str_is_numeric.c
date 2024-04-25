/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:02:35 by atang             #+#    #+#             */
/*   Updated: 2023/05/29 16:36:37 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>
*/
int	ft_str_is_numeric(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if ((*str < '0' || *str > '9'))
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

	strcpy(str1, "0212");
	strcpy(str2, "021alphabet");
	strcpy(str3, "ALPHABET");
	strcpy(str4, "\0");
	printf("%d\n", ft_str_is_numeric(str1));
	printf("%d\n", ft_str_is_numeric(str2));
	printf("%d\n", ft_str_is_numeric(str3));
	printf("%d\n", ft_str_is_numeric(str4));
	return (0);
}
*/
