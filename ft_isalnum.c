/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:22:46 by atang             #+#    #+#             */
/*   Updated: 2023/07/16 19:53:17 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* int	main(void)
{
	char ch = '%';

	if (ft_isalnum(ch) == 1)
		printf("The character '%c' is alphanumeric.\n", ch);
    else
		printf("The character '%c' is not alphanumeric.\n", ch);
    return (0);
} */
