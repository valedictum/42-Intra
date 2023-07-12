/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:12:16 by atang             #+#    #+#             */
/*   Updated: 2023/07/12 17:26:51 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == " ")
		i++;
	if (str[i] == "-")
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int main()
{
	const char str[] = " -12345";
	int num = ft_atoi(str);

	printf ("%d\n", num);
	return (0);
}
