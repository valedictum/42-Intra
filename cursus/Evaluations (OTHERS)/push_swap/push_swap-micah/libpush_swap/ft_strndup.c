/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:26:45 by mickim            #+#    #+#             */
/*   Updated: 2023/12/29 12:26:47 by mickim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

char	*ft_strndup(const char *str, size_t size)
{
	char	*pika;
	size_t	len;

	if (!str || size == 0)
	{
		pika = (char *)ft_calloc(1, sizeof(char));
		if (!pika)
			return (NULL);
		*pika = '\0';
		return (pika);
	}
	len = 0;
	while (len < size && str[len])
		len++;
	pika = (char *)malloc((size + 1) * (sizeof(char)));
	if (!pika)
		return (NULL);
	ft_memcpy(pika, str, len);
	pika[size] = '\0';
	return (pika);
}
