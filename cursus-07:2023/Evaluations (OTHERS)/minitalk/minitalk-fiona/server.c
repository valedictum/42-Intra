/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 09:42:11 by fsalimba          #+#    #+#             */
/*   Updated: 2023/09/08 09:42:53 by fsalimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./ft_printf/ft_printf.h"

void	ft_sig_handler(int sig)
{
	static int	byte = 0;
	static int	pos = 7;

	if (sig == SIGUSR1)
		byte += (0 << pos);
	else
		byte += (1 << pos);
	if (pos == 0)
	{
		ft_printf("%c", byte);
		byte = 0;
		pos = 7;
	}
	else
		pos--;
}

int	main(void)
{
	if (ft_printf("pid: %d\n", getpid()) < 0)
		return (0);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
