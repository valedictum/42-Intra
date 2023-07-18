/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:09:10 by atang             #+#    #+#             */
/*   Updated: 2023/07/18 11:44:52 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)b;
	i = 0;
	while (i < len)
	{
		*ptr = (char) c;
		ptr++;
		i++;
	}
}

/* int main(void)
{
    char str[21];

    ft_memset(str, 'A', sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';
	printf("Filled string: %s\n", str);
    return 0;
} */
