/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:58:30 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 20:04:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/* int main()
{
    int c = 'Q';
	int result = ft_tolower(c);
    printf("Character is: %c\n", c);    
    printf("Lowercase equivalent: %c\n", result);
    return (0);
} */
