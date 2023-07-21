/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:52:35 by jong              #+#    #+#             */
/*   Updated: 2023/07/20 01:27:28 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	n;

	if (!dst && !src)
	{
		return (NULL);
	}
	n = 0;
	if (src < dst)
	{
		n = len;
		while (n > 0)
		{
			n--;
			((unsigned char *) dst)[n] = ((unsigned char *) src)[n];
		}
	}
	else
	{
		while (n < len)
		{
			((unsigned char *) dst)[n] = ((unsigned char *) src)[n];
			n++;
		}
	}
	return (dst);
}
