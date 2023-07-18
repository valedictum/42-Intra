/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:11:59 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 11:24:03 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_ptr;
	char	*src_ptr;

	i = 0;
	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}

/* int main()
{
    char src[] = "Hello World!";
    char dst[20];

    size_t n = ft_strlen(src) + 1;

    ft_memcpy(dst, src, n);
	printf("Copied string: %s\n", dst);
	return (0);
} */