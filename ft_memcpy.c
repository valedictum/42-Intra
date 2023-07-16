/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:49:39 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 20:30:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy (void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	i;
	char			*dst_ptr;
	const char		*src_ptr;

	i = 0;
	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

int	main(void)
{
	char	dst[10];
	char	src[] = "Hello World!";

	printf ("Adjusted 5: %s\n", (char *)ft_memcpy(dst, src, 5));
	printf ("Adjusted 8: %s\n", (char *)ft_memcpy(dst, src, 8));
	return (0);
}
