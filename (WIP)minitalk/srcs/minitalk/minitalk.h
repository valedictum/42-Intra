/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:23:53 by atang             #+#    #+#             */
/*   Updated: 2023/11/26 21:10:38 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../../libs/printf/ft_printf.h"

int		ft_atoi(const char *str);
void	setup_signal_handlers(void);
void	send_signal(int pid, unsigned char character);
void	handle_signal(int signal, siginfo_t *info, void *context);

#endif
