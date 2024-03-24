/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:38:34 by atang             #+#    #+#             */
/*   Updated: 2023/06/04 12:44:30 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		putchar(str[index]);
		index++;
	}	
}

int	main(int argc, char *argv[])
{
	int	index;

	index = argc - 1;
	while (index != 0)
	{
		putstr(argv[index]);
		putstr("\n");
		index--;
	}
	return (0);
}
