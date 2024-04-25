/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:00:22 by atang             #+#    #+#             */
/*   Updated: 2023/05/24 09:48:03 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	outcome;

	if (n < 0)
	{
		outcome = 'N';
	}
	else
	{
		outcome = 'P';
	}	
	write(1, &outcome, 1);
}
/*
int	main(void)
{
	ft_is_negative(-2);
	ft_is_negative(0);
	ft_is_negative(2);
	return (0);
}
*/
