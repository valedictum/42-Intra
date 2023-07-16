/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:37:08 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 19:58:34 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/* int main() {
    int ch = '&';
    
    printf("The character is: %c\n", ch);
    if (ft_isprint(ch))
        printf("The character '%c' is printable.\n", ch);
    else
        printf("The character '%c' is not printable.\n", ch);
    return (0);
} */
