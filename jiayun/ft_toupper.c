/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jong <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:15:03 by jong              #+#    #+#             */
/*   Updated: 2023/07/13 20:30:23 by jong             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (ft_toupper(c - 32));
	}
	return (c);
}
/*
int main() {
    char ch = 'a';
    int uppercase = ft_toupper(ch);

    printf("Original character: %c\n", ch);
    printf("Uppercase character: %c\n", uppercase);

    return 0;
}
*/
