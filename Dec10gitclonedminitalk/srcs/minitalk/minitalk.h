/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:23:53 by atang             #+#    #+#             */
/*   Updated: 2023/12/15 01:22:53 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../../libs/printf/ft_printf.h"

// client.c + client_bonus.c
int		mt_atoi(const char *str);
void	send_signal(int pid, unsigned char character);

// server.c
void	handle_signal(int signal, siginfo_t *info, void *context);
// server_bonus.c
void    handle_signal_b(int signal, siginfo_t *info, void *context);

#endif
