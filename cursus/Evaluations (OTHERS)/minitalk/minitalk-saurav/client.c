/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:08:28 by sasharma          #+#    #+#             */
/*   Updated: 2023/08/03 11:32:16 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int		ft_atoi(char *str, int *res);
void	ft_putchar(char c);
void	ft_putstr(char *str);

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}

int	send_error(int pid, char *str)
{
	if (kill(pid, 0) == -1)
	{
		ft_putstr("Invalid PID\n");
		return (1);
	}
	else
	{
		if (pid == 0)
		{
			ft_putstr("Invalid PID\n");
			return (1);
		}
		send_message(pid, str);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	if (ft_atoi(argv[1], &pid) == 0)
	{
		ft_putstr("Invalid Argumenrt");
		return (1);
	}
	else
		return (send_error(pid, argv[2]));
}
