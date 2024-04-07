/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:37:43 by sentry            #+#    #+#             */
/*   Updated: 2024/04/07 17:53:30 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
(CTRL-C)
handle_interrupt() - writes a new line, moves the readline cursor to 
a new line, replaces the current line with an empty string and redisplays 
the prompt if standard input is a terminal
*/

void	handle_interrupt(int sig)
{
	(void)sig;
	if (isatty(STDIN_FILENO))
	{
		// Write terminal escape sequence to clear current line
		write(STDOUT_FILENO, "\033[2K\r", 4);
		write(STDOUT_FILENO, "\n", 1);
		// Write carriage return character to return cursor to the start of the line
		//write(STDOUT_FILENO, "\r", 1);
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/*
(CTRL-\)
handle_quit() checks if the standard input is a terminal. If yes, the 
SIGQUIT(CTRL-\) signal is ignored. fn does nothing (as CTRL-\ is supposed to)
*/

void	handle_quit(int sig)
{
	if (isatty(STDIN_FILENO))
	{
		(void)sig;
		signal(SIGQUIT, SIG_IGN);
	}
	//printf("Do nothing\n");
	return ;
}

/*
(CTRL-C and CTRL-\)
Registers signal handlers for SIGINT(CTRL-C) and SIGQUIT(CTRL-\)
*/

void	setup_signal_handlers(void)
{
	signal(SIGINT, handle_interrupt);
	signal(SIGQUIT, handle_quit);
}

/*
(CTRL-C and CTRL-\)
Resets signal handlers for SIGINT(CTRL-C) and SIGQUIT(CTRL-\) to defaults
*/

void	reset_signal_handlers(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
