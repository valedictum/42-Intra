/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:37:31 by jong              #+#    #+#             */
/*   Updated: 2023/07/17 19:31:26 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numl(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*tmp;
	long	nb;

	len = ft_numl(n);
	nb = n;
	tmp = (char *)malloc(len + 1);
	if (tmp == NULL)
		return (NULL);
	if (nb < 0)
	{
		tmp[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		tmp[0] = '0';
	tmp[len--] = '\0';
	while (nb != '\0')
	{
		tmp[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (tmp);
}
/*
int main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(987654321));
	printf("%s\n", ft_itoa(-123456789));
}
*/
