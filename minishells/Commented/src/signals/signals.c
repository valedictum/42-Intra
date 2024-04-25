/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:37:43 by sentry            #+#    #+#             */
/*   Updated: 2024/04/13 16:00:38 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
(CTRL-C)
handle_interrupt() - writes a new line, moves the readline cursor to 
a new line, replaces the current line with an empty string and redisplays 
the prompt if standard input is a terminal
*/

/**
 * handle_interrupt - Handles SIGINT(CTRL-C) signal.
 * @sig: Unused signal number.
 *
 * Handles SIGINT signal by writing a new line to standard output, moving the
 * readline cursor to a new line, replacing the current line with an empty
 * string and redisplays the prompt if standard input is a terminal.
 *
 * This function is called when the user presses CTRL-C.
 */
void	handle_interrupt(int sig)
{
	(void)sig;					/* Unused variable */
	if (isatty(STDIN_FILENO))		/* If standard input is a terminal */
	{
		write(STDOUT_FILENO, "\n", 1);	/* Write a new line to stdout */
		rl_on_new_line();			/* Move readline cursor to new line */
		rl_replace_line("", 0);		/* Replace current line with an empty string */
		rl_redisplay();			/* Redisplay the prompt */
	}
}

/*
(CTRL-\)
handle_quit() checks if the standard input is a terminal. If yes, the 
SIGQUIT(CTRL-\) signal is ignored. fn does nothing (as CTRL-\ is supposed to)
*/

/**
 * handle_quit - Handles SIGQUIT(CTRL-\\) signal.
 * @sig: Unused signal number.
 *
 * If standard input is a terminal, sets the SIGQUIT signal handler to SIG_IGN
 * (ignore the signal). This is done so that the shell does not terminate when
 * the user presses CTRL-\\ (SIGQUIT). Instead, the signal is ignored, and the
 * shell continues to run as usual.
 *
 * Return: None.
 */
void	handle_quit(int sig)
{
	if (isatty(STDIN_FILENO))
	{
		/* If standard input is a terminal, ignore SIGQUIT signal */
		(void)sig;
		signal(SIGQUIT, SIG_IGN);
	}
	/* Do nothing */
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
