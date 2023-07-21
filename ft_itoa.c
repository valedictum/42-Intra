/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:52:59 by atang             #+#    #+#             */
/*   Updated: 2023/07/21 11:30:24 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Function name
	ft_itoa

Prototype
	char *ft_itoa(int n);

Parameters
	n: the integer to convert.

Return value
	The string representing the integer. 
	NULL if the allocation fails.

External functs.
	malloc

Description
	Allocates (with malloc(3)) and returns a string representing the integer 
	received as an argument. Negative numbers must be handled.
*/

#include "libft.h"

static int	count_digits(int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char	*ft_itoa(int num)
{
	int		sign_len; 
	int		len;
	char	*str;

	sign_len = (num < 0);
	len = count_digits(num);
	str = (char *)malloc((len + sign_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len + sign_len] = '\0';
	while (len-- > 0)
	{
		if (sign_len)
			str[len + sign_len] = -(num % 10) + '0';
		else
			str[len + sign_len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign_len)
		str[0] = '-';
	return (str);
}

/* 
int	main(void)
{
	int		num = -23487967;
	char	*result = ft_itoa(num);

	if (result != NULL)
	{
		printf("ft_itoa(%d) = %s\n", num, result);
		free(result);
	}
	return (0);
}
 */
