/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:21:23 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 19:53:57 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/* int main()
{
    int c = '7';

	printf("The character is: %c\n", c);
    if (ft_isalpha(c))
        printf("The character is alphabetical.\n");
    else
        printf("The character is not alphabetical.\n");
    return (0);
} */