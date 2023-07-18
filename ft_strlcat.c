/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:18:13 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 13:37:20 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len; 
	size_t	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	while (i < (dstsize - dst_len - 1) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* int main(void)
{
    char destination[20] = "Hello, ";
    const char *source = "world!";
    size_t dstsize = sizeof(destination);
    
    printf("Before concatenation:\n");
    printf("Destination: %s\n", destination);
    printf("Source: %s\n", source);
    
    size_t result = ft_strlcat(destination, source, dstsize);
    
    printf("\nAfter concatenation:\n");
    printf("Destination: %s\n", destination);
    printf("Resultant length: %zu\n", result);
    
    return 0;
} */
