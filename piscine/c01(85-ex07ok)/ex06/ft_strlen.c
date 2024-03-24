/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:25:23 by atang             #+#    #+#             */
/*   Updated: 2023/05/25 14:51:24 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*
int	main(void)
{
	char	*str;

	str = "Hello there!";
	printf("%s\n", str);
	printf("Number of characters: %d\n", ft_strlen(str));
	return (0);
}
*/
