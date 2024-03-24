/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:14:31 by atang             #+#    #+#             */
/*   Updated: 2023/06/04 11:38:14 by atang            ###   ########.fr       */
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
	(void) argc;
	putstr(argv[0]);
	putstr("\n");
	return (0);
}
