/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:42:07 by atang             #+#    #+#             */
/*   Updated: 2023/06/03 14:20:02 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return ;
	}
	else
	{
		if (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
			ft_putstr(&str[i]);
		}
	}
}
/*
int	main(void)
{
	ft_putstr("hellohello world");
	return (0);
}
*/
