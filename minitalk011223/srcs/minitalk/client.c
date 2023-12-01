/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:18:52 by atang             #+#    #+#             */
/*   Updated: 2023/12/01 19:31:14 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
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

/*
FUNCTION - setup_signal_handlers

USAGE - Sets up signal handlers for SIGUSR1 and SIGUSR2 using handle_signal
function to process them.

'sigaction' structure (sa) is set up to handle signalling behaviour.

'sa.sa_sigaction = handle_signal' assigns the signal handler 
function handle_signal to the sa_sigaction member of the struct sigaction 
and tells the system to call 'handle_signal' when a signal is received. 

'sa.sa_flags = SA_SIGINFO' sets the sa_flags member of the struct 
'sigaction' to SA_SIGINFO. This flag informs the operating system that the 
signal handler function is using extended information (siginfo_t and 
void *context parameters) instead of just the basic signal number.
SA_SIGINFO is a flag that tells the signal handler to expect 
extended information about the signal through the siginfo_t and
void *context parameters when handling the signal. This extended information 
can include details like the process ID of the sender etc. allowing for 
more detailed handling of signals.

'sigemptyset(&sa.sa_mask)' initialises the signal mask sa_mask to an empty set,
meaning no signals are blocked while the signal handler is executing allowing 
all signals to be delivered while the handler runs.

'sigaction(SIGUSR1, &sa, NULL)' sets up a signal handler for SIGUSR1 using the 
configuration specified in sa. The signal handler function handle_signal will 
handle SIGUSR1 signals. Same goes for SIGUSR2.
*/

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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

'usleep(100)' pauses the program execution for a short duration 
(100 microseconds) to control the speed at which signals are sent, then bit 
is incremented to move to the next bit of the character.
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
		usleep(100);
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
	char	*message;

	i = 0;
	message = argv[2];
	if (argc == 3)
	{
		setup_signal_handlers();
		pid = ft_atoi(argv[1]);
		while (message[i] != '\0')
		{
			send_signal(pid, message[i]);
			i++;
		}
		send_signal(pid, '\n');
		pause();
	}
	else
	{
		ft_printf("Error!\nCorrect format is: ./client <PID> <MESSAGE>\n");
		return (-1);
	}
	return (0);
}
