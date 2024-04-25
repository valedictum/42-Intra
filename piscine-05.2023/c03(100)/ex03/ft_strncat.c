/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:36:55 by atang             #+#    #+#             */
/*   Updated: 2023/05/30 21:05:50 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)

{
	unsigned int	dest_len;
	unsigned int	i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}
	while ((i < nb) && (src[i] != '\0'))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "Alphabet!";
	unsigned int	nbr = 6;

	printf("Dest = %s\n", str1);
	printf("Src = %s\n", str2);
	printf("Dest = %s\n", ft_strncat(str1, str2, nbr));
	return (0);
}
*/
