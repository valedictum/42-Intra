/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:02:38 by atang             #+#    #+#             */
/*   Updated: 2024/04/25 18:25:26 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include	<unistd.h> // write, usleep
#include 	<stdio.h> // printf
#include	<stdlib.h> // malloc, free
#include    <limits.h>
#include    <stdbool.h> 
#include	<pthread.h> // mutex: init, destroy, lock, unlock
                        // threads: create, join, detach
#include    <sys/time.h> // gettimeofday
#include    <limits.h> // INT_MAX
#include 	<errno.h>

/*
** ANSI Escape Sequences for Bold Text Colors
** Usage: 
**     printf(R "This is red text." RST);
**     printf(B "This is blue text." RST);
** Remember to use RST to reset the color after setting it.
*/

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

// OPCODE for mutex | thread fns
typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}		t_opcode;

typedef pthread_mutex_t t_mtx;

// IOU FOR COMPILER//
typedef struct s_data t_data;  


// FORK //
typedef struct s_fork
{
    t_mtx   fork;   
    int     fork_id;
}       t_fork;

// PHILO //
typedef struct s_philo
{
    int             philo_id;
    long            meal_count;
    bool            full;
    long            last_meal_time; // time passed from last meal
    t_fork          *left_fork;
    t_fork          *right_fork;
    pthread_t       thread_id; // a philo is a thread
    struct s_data  *data;
}       t_philo;

// DATA //
typedef struct s_data
{
    long    num_of_philos;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    num_limit_meals; // [5] optional | FLAG if -1
    long    start_sim; // time
    bool    end_sim; // triggered when a philo dies | all philos are full
    //bool    all_philos_ready;
    //bool    all_philos_full;
    //long    num_of_threads;
    t_fork  *forks; // array of forks
    t_philo *philos; // array of philos
}		t_data;

// init.c //
void    init_data(t_data    *data);

// safe.c //
void	*safe_malloc(size_t bytes);
void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode);

// utils.c //
void	error_and_exit(const char	*error_msg);

// parse.c //
void    parse_input(t_data *data, char **argv);

#endif