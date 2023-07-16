/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:42:43 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 20:59:29 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove (void *dst, const void *src, size_t len)
{
	char	*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (const char *)src;

	if (dst_ptr == src_ptr)
		return (dst);
	if (dst_ptr < src_ptr)
	{
		size_t i = 0;
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		size_t i = len;
		while (i > 0)
		{
			dst_ptr[i - 1] = src_ptr[i -1];
			i--;
		}
	}
	return (dst);
}

int main(void)
{
    char dst[10] = "123456789";
    char src[10] = "AbcdeF";

    printf("Before ft_memmove:\n");
    printf("Dst: %s\n", dst);
    printf("Src: %s\n", src);

    ft_memmove(dst + 2, dst, 4);

    printf("\nAfter ft_memmove:\n");
    printf("Dst: %s\n", dst);
    printf("Src: %s\n", src);

    return 0;
}
