/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:57:39 by atang             #+#    #+#             */
/*   Updated: 2023/06/03 13:48:16 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stddef.h>
#include <stdio.h>
*/
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
	{
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	//ualarm(100, 0);
	printf("%i,%i,%i",
		ft_strlen("hello world"),
		ft_strlen("hello \0world"),
		ft_strlen(NULL));
}
*/
