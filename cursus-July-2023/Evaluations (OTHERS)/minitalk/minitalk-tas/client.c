/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:30:42 by tday              #+#    #+#             */
/*   Updated: 2023/11/05 13:49:56 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*

void	handle_signal(int signal);

Summary
This function accumulates bits received through the SIGUSR1 signal and assembles
them into bytes. When a complete byte is received, it checks if it's a newline
character or not and performs the appropriate action, either writing the byte to
the standard output or writing a newline character. The function keeps track of
the end of transmission using the eot variable and terminates the program when
the transmission is complete.

Inputs
signal: an integer representing the signal received by the program.

Flow
1. Check if the end of transmission (EOT) signal has been received. If yes,
return from the function.
2. Check if the received signal is SIGUSR1 representing a '1' bit.
3. If the signal is SIGUSR1, set the corresponding bit in the byte variable
to 1.
4. Increment the bit counter.
5. If the bit counter reaches 8, it means a complete byte has been received.
6. Check if the byte is equal to the newline character ('\n'). If yes, write a
newline character to the standard output and set the EOT flag.
7. If the byte is not equal to newline, write the byte to the standard output.
8. Reset the bit counter and byte variable.
9. If the EOT flag is set, exit the program.

Outputs
None. The function writes bytes to the standard output and may exit the program
if the end of transmission signal is received.

*/
void	handle_signal(int signal)
{
	static unsigned char	byte = 0;
	static int				bit = 0;
	static int				eot = 0;

	if (eot)
		return ;
	if (signal == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (byte == '\n')
		{
			write(1, "\n", 1);
			eot = 1;
		}
		else
			write(1, &byte, 1);
		bit = 0;
		byte = 0;
		if (eot)
			exit (0);
	}
}

/*

void	setup_signal_handlers(void);

Summary
The setup_signal_handlers function configures the handling of SIGUSR1 and
SIGUSR2 signals to use the handle_signal function as the common signal
handler for both signals. When either of these signals is received, the
handle_signal function will be called to handle them. This is a way to
define custom behavior for these signals within the context of the program.

Inputs
None.

Flow
1. Create a struct sigaction variable named sa.
2. Set the sa.sa_handler field to the handle_signal function.
3. Set the sa.sa_flags field to 0.
4. Clear the signal mask using sigemptyset(&sa.sa_mask).
5. Set up the signal handler for the SIGUSR1 signal using
sigaction(SIGUSR1, &sa, NULL).
6. Set up the signal handler for the SIGUSR2 signal using
sigaction(SIGUSR2, &sa, NULL).

Outputs
None.

*/
void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

/*

This is explained in server.c as well

void	bit_signal(int pid, const char *str);

Summary
The bit_signal function converts a string of characters into a series of binary
bits, sending corresponding signals (SIGUSR1 for '1' bits and SIGUSR2 for '0'
bits) to the specified target process with a controlled timing delay between
each signal transmission.

Inputs
pid: an integer representing the process ID of the receiving process.
str: a pointer to a null-terminated string containing the message to be
transmitted.

Flow
1. Iterate through each character in the message string.
2. Convert the character to its binary representation and store it in the byte
variable.
3. Iterate through each bit in the binary representation.
4. If the bit is 1, send the SIGUSR1 signal to the process identified by pid.
5. If the bit is 0, send the SIGUSR2 signal to the process identified by pid.
6. Pause for a short period of time using usleep to allow the receiving process
to handle the signal.
7. Move to the next bit.
8. Move to the next character in the message string.
9. Repeat steps 2-8 until the entire message has been transmitted.

Outputs
None. The function sends signals to the receiving process to transmit the
message.

** N.B. **
(byte & (0x01 << bit)) != 0
The way this works to check if the current bit is a '1' or '0' is by using
0x01 << bit to create a byte that is all 0's eacept a 1 in the bit position.
It then compares that new byte to the original byte using bitwise &, which
compares the individual bits of each byte and only returns 1 if both
corresponding bits are 1.

0 & 0 = 0
0 & 1 = 0
1 & 0 = 0
1 & 1 = 1

so for byte = 0b00101010, bit = 3

0x01 << bit = 0b00001000 (bit counts from 0)

   00101010
 & 00001000
 -----------
   00001000

0b00001000 != 0 so bit 3 is a 1

*/
void	bit_signal(int pid, const char *str)
{
	unsigned char	byte;
	int				bit;

	while (*str != '\0')
	{
		byte = *str;
		bit = 0;
		while (bit < 8)
		{
			if ((byte & (0x01 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(120);
			bit++;
		}
		str++;
	}
}

/*

Summary
The main function is the entry point of the program. It checks if the correct
number of command line arguments are provided, sets up signal handlers,
converts the first argument to an integer, sends a signal to the specified
process ID, and then enters an infinite loop, waiting for signals.

*/
int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		setup_signal_handlers();
		pid = ft_atoi(argv[1]);
		bit_signal(pid, argv[2]);
		bit_signal(pid, "\n");
		while (1)
			pause();
	}
	else
	{
		ft_printf("Error!\nCorrect format: ./client <PID> <MESSAGE>\n");
		return (-1);
	}
	return (0);
}
