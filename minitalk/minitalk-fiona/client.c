/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:41:01 by fsalimba          #+#    #+#             */
/*   Updated: 2023/09/08 09:41:03 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	ft_sig_sender(char *str, int pid)
{
	int				pos;
	unsigned char	chr;

	while (*str)
	{
		pos = 7;
		chr = *str;
		while (pos >= 0)
		{
			if ((chr >> pos) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
			pos--;
		}
		str++;
	}
}

int	ft_atoi(char *c)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (*c == ' ' || *c == '\f' || *c == '\n' || *c == '\r'
		|| *c == '\t' || *c == '\v')
		c++;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			sign = -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
	{
		res = res * 10 + (*c - '0');
		c++;
	}
	return (sign * res);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		ft_printf("Args Error\n");
	else
		ft_sig_sender(argv[2], ft_atoi(argv[1]));
	return (0);
}
