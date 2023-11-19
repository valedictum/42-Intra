/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:56:53 by tday              #+#    #+#             */
/*   Updated: 2023/11/03 23:59:04 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*

This is explained in client.c as well

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

void	sig_handle(int signal, siginfo_t *info, void *context);

Summary
The sig_handle function is responsible for handling signals received by the
server process. It extracts information from the signal, such as the client
process ID and the signal type, and uses this information to process the
received data. It constructs bytes from the bits received, and writes them
to the standard output and also sends a message back to the client after it
has recieved the entire message.

Inputs
signal: an integer representing the signal received by the server process.
info: a pointer to a siginfo_t structure that contains information about
the signal, such as the process ID of the client.
context: a pointer to a context structure that is not used in this function.

Flow
1. If client_pid is 0, assign the process ID of the client to client_pid.
2. If the received signal is SIGUSR1, set the corresponding bit in the byte
variable using bitwise OR.
3. Increment the bit variable.
4. If bit is equal to 8, it means that a full byte has been received.
5. Write the byte to the standard output.
6. If the byte is equal to a newline character, call the bit_signal function
to send a response message to the client.
7. Reset the bit and byte variables to 0.

Outputs
None. The function processes the received signals and performs actions based
on the content of the signals.

*/
void	sig_handle(int signal, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	byte = 0;
	static int				client_pid = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (signal == SIGUSR1)
		byte |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		if (byte == '\n')
		{
			bit_signal(client_pid, "👉😉👉\n");
			client_pid = 0;
		}
		bit = 0;
		byte = 0;
	}
}

/*

The main function is the entry point of the program. It sets up the signal
handling for the server process, prints the servers PID, and waits for
incoming signals from the client.

*/
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error! Expected no arguments\n");
		return (-1);
	}
	ft_printf("PID: %i\n", getpid());
	ft_printf("Waiting for client...\n");
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handle;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause ();
	return (0);
}
