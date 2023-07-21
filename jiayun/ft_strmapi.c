/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:14:01 by jong              #+#    #+#             */
/*   Updated: 2023/07/18 11:19:17 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	example(unsigned int i, char str)
{
	printf("Inner function: index = %d and %c\n", i, str);
	return (str - 32);
}

int main(void)
{
	char str[10] = "coffeepls";
	printf("The prototype is: %s\n", str);
	char *result = ft_strmapi(str, example);
	printf("The result for the prototype is: %s\n", result);
	return (0);
}
*/
