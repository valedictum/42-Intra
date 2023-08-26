/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:49:42 by atang             #+#    #+#             */
/*   Updated: 2023/05/24 09:45:46 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)

{
	int	count;

	count = 47;
	while (count++ <= 56)
		write (1, &count, 1);
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
