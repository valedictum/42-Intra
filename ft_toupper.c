/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:34:24 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 20:02:55 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/* int main()
{
    int c = 'b';
	int result = ft_toupper(c);
    printf("Character is: %c\n", c);    
    printf("Uppercase equivalent: %c\n", result);
    return (0);
} */