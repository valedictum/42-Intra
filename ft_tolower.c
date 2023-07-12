/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:58:30 by atang             #+#    #+#             */
/*   Updated: 2023/07/12 17:32:49 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

int	main(void)
{
	char	str1[100];
	char	str2[100];
	char	str3[100];
	char	str4[100];

	strcpy(str1, "A");
	strcpy(str2, "1A");
	strcpy(str3, "AbcD");
	strcpy(str4, "\0");
	ft_tolower(str1);
	ft_tolower(str2);
	ft_tolower(str3);
	ft_tolower(str4);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);
	return (0);
}
