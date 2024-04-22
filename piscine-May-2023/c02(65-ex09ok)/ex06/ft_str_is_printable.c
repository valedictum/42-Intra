/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:26:50 by atang             #+#    #+#             */
/*   Updated: 2023/05/29 18:34:22 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/

int	ft_str_is_printable(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str < 32 || *str > 126)
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
	printf("%d\n", ft_str_is_printable(str1));
	printf("%d\n", ft_str_is_printable(str2));
	printf("%d\n", ft_str_is_printable(str3));
	printf("%d\n", ft_str_is_printable(str4));
	return (0);
}
*/
