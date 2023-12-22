/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:58:58 by sasharma          #+#    #+#             */
/*   Updated: 2023/08/04 11:21:47 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

pid_t	getpid(void);
void	ft_putchar(char c);
void	ft_putnbr(int nb);

pid_t	g_clientpid = -1;

void	record(int n, int pid)
{
	int				shift;
	static int		i = 7;
	static char		c;

	if (i == -1 || pid != g_clientpid)
	{
		i = 7;
		c = 0;
		g_clientpid = pid;
	}
	shift = 1 << (i);
	if (n != 0)
		c = (c | shift);
	i--;
	if (i == -1)
		write(1, &c, 1);
}

void	server(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write (1, "\n", 1);
}

void	signal_handler(int sig, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (sig == SIGUSR1)
		record(1, info-> si_pid);
	else
		record(0, info-> si_pid);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	server();
	while (1)
		pause();
	return (0);
}
