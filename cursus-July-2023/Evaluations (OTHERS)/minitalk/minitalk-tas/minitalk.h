/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:27:30 by tday              #+#    #+#             */
/*   Updated: 2023/11/03 23:45:45 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include "libft/ft_printf/includes/libftprintf.h"

void	handle_signal(int signal);
void	setup_signal_handlers(void);
void	bit_signal(int pid, const char *str);
void	sig_handle(int signal, siginfo_t *info, void *context);

#endif