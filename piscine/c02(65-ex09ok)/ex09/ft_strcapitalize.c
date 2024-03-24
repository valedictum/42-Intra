/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitlize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:29:25 by atang             #+#    #+#             */
/*   Updated: 2023/05/29 19:58:05 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
*/

int	ft_space(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (0);
	else
		return (1);
}

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[0] - 'a' + 'A';
	while ((str[i]) && (str[i + 1]))
	{
		if (ft_space(str[i]) == 1 && str[i + 1] >= 'a'
			&& str[i + 1] <= 'z')
			str[i + 1] = str[i + 1] - 'a' + 'A';
		if (ft_space(str[i]) == 0 && str[i + 1] >= 'A'
			&& str[i + 1] <= 'Z')
			str[i + 1] = str[i + 1] - 'A' + 'a';
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	newstr[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(newstr));
	return (0);
}
*/
