/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:18:56 by atang             #+#    #+#             */
/*   Updated: 2023/11/26 21:10:37 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	assembled_byte = 0;
	static int				bit = 0;

	(void)info;
	(void)context;
	if (bit == 0)
	{
		assembled_byte = 0;
	}
	if (signal == SIGUSR1)
	{
		assembled_byte |= (0x01 << bit);
	}
	bit++;
	if (bit == 8)
	{
		write(1, &assembled_byte, 1);
		bit = 0;
	}
	else
	{
		assembled_byte <<= 1;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error!");
		return (-1);
	}
	ft_printf("This is Andrew's server.\n");
	ft_printf("Server PID is: %d\n", getpid());
	ft_printf("Waiting for message from client...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
