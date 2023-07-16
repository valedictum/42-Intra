/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:06:55 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 16:36:31 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		ft_memset(s, 0, n);
	}
}

/* int main() 
{
    char buffer[10] = "Hello";
    
    printf("Original: %s\n", buffer);
    ft_bzero(buffer, sizeof(buffer));
    printf("After ft_bzero: %s\n", buffer);
    return (0);
} */