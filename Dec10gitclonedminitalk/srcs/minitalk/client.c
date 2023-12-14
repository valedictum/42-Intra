/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:18:52 by atang             #+#    #+#             */
/*   Updated: 2023/12/15 01:23:06 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
'mt_atoi' is used to convert a string to an integer (process ID aka pid).
*/

int	mt_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

/*
FUNCTION - send_signal

USAGE - Sends SIGUSR1 (bit set to 1) and SIGUSR2 (bit set to 0) signals to a 
specified process ID (pid) to represent the individual bits of a character.

'bit' is initiliased to 0 and used to iterate over each bit of a character 
being sent. While bit is < 8, the bitwise AND operation is used and:
- if the result is 0 (meaning the specific bit in the character is 1), a SIGUSR1 
signal is sent to the pid using the kill function.
- if the bit in the character is 0, a SIGUSR2 signal is sent to the pid using 
the kill function.

'usleep(500)' pauses the program execution for 500 microseconds to control 
the speed at which signals are sent, then bit is incremented to move to the 
next bit of the character.
*/

void	send_signal(int pid, unsigned char character)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((character & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

/*

// TO BE WORKED ON!
FUNCTION - main

USAGE - Entry point.

'sigaction' structure (sa) is set up to handle signalling behaviour.

'sa.sa_flags = SA_SIGINFO' sets the sa_flags member of the struct 
'sigaction' to SA_SIGINFO. This flag informs the operating system that the 
signal handler function is using extended information (siginfo_t and 
void *context parameters) instead of just the basic signal number.
SA_SIGINFO is a flag that tells the signal handler to expect 
extended information about the signal through the siginfo_t and
void *context parameters when handling the signal. This extended information 
can include details like the process ID of the sender etc. allowing for 
more detailed handling of signals.

'sa.sa_sigaction = handle_signal' assigns the signal handler 
function handle_signal to the sa_sigaction member of the struct sigaction 
and tells the system to call 'handle_signal' when a signal is received. 

If argc = 1 (server, so no command line arguments), signal handlers are set up 
for SIGUSR1 and SIGUSR2 using sigaction. 'pause()' is used to pause the 
program execution waiting for signals to arrive, at which point 'handle_signal' 
signal handler will be executed.
*/

int	main(int argc, char **argv)
{
	int		i;
	int		pid;

	i = 0;
	if (argc == 3)
	{
		pid = mt_atoi(argv[1]);
		while(argv[2][i] != 0)
		{
			send_signal (pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\n');
	}
	else
	{
		ft_printf("Error!\nCorrect format is: ./client <PID> <MESSAGE>\n");
		return (-1);
	}
	return (0);
}
