/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:38 by atang             #+#    #+#             */
/*   Updated: 2024/03/06 21:12:41 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include	<unistd.h>
#include 	<stdio.h>
#include	<stdlib.h>
#include    <limits.h>
#include    <stdbool.h> 
#include	<pthread.h>

typedef struct s_fork
{
    int     fork_num;
}       t_fork;

typedef struct s_philo
{
    int             philo_num;
    bool            full;
    long            eat_count;
    struct s_data  *data;
}       t_philo;

typedef struct s_data
{
    long    num_of_philos;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    num_of_eats;
    bool    end_sim;
    bool    all_philos_ready;
    bool    all_philos_full;
    long    num_of_threads;
    t_fork  *fork;
    t_philo *philo;
}		t_data;


// init.c //
void    init_data(t_data    *data);

// utils.c //
void	error_and_exit(const char	*error_msg);

// parse.c //
void    parse_input(t_data *data, char **argv);

#endif