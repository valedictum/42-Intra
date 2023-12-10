/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:18:56 by atang             #+#    #+#             */
/*   Updated: 2023/12/10 16:48:58 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
PROGRAM - SERVER
The server program listens to signals ('SIGUSR1' and 'SIGUSR2') from a client.
When 'SIGUSR1' signal is received, it sets individual bits and then prints the 
corresponding character when 8 bits are accumulated to form a byte.
The server program initialises a signal handler using 'sigaction' to catch these
signals and executes the 'handle_signal' function whilst waiting indefinitely
for signals using 'pause()'. 
*/

/*
FUNCTION - handle_signal

USAGE - Accumulates bits received via SIGUSR1 signals and prints the 
corresponding character to the standard output when 8 bits have been collected.

'info' (additional signal information) and 'context' (program state information)
are used to match the signature required by sigaction when using the 'SA_SIGINFO'
flag but they are unused so they are silenced.
'i' and 'bit' are both static integers which retain their values across function calls.
If signal is SIGUSR1, i is bit-shifted to the left using the bitwise OR operator.
If 8 bits have been accumulated, the contents of integer 'i' are written to the
standard output as a single byte (char). 'Bit' and 'i' are then reset to zero to 
start accumulating bits for the next character from scratch. 
*/


// WORKING
void handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	static int	i = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

/*
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
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error!");
		return (-1);
	}
	ft_printf("This is Andrew's server\n");
	ft_printf("Server PID is: %d\n", getpid());
	ft_printf("Waiting for message from client...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
