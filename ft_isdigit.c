/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:20:51 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 19:54:23 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/* int main()
{
    int c = 'A';

    printf("The character is: %c\n", c);
    if (ft_isdigit(c))
        printf("%c is a digit.\n", c);
    else
        printf("%c is not a digit.\n", c);
    return (0);
} */