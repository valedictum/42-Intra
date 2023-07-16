/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:22:32 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 20:27:44 by atang            ###   ########.fr       */
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

/* int	main(void)
{
	char buffer [10];
	size_t i = 0;

	ft_memset(buffer, 'Y', sizeof(buffer));
	while (i < sizeof(buffer))
	{
		printf("%c ", buffer[i]);
		i++;
	}
	return (0);
} */
