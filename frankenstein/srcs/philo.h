/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:42:40 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 19:01:30 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>
//#include <limits.h>

typedef pthread_mutex_t	t_mtx;
//typedef pthread_t		t_pthrd;
typedef struct s_table	t_table;

/* int values */

#define INT_MIN	-2147483648
#define INT_MAX	2147483647

/* text colours */

#define RST		"\033[0m"
#define GRAY	"\033[1;30m"
#define R		"\033[1;31m"
#define G		"\033[1;32m"
#define Y		"\033[1;33m"
#define B		"\033[1;34m"
#define M		"\033[1;35m"
#define C		"\033[1;36m"
#define W		"\033[1;37m"

/* write function debug macro */

#define DEBUG_MODE	0

// PHILO MAX - by default is 200
# ifndef PHILO_MAX
#   define PHILO_MAX 200 
# endif

/* OPCODE for mutexe & thread functions */

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}			t_opcode;

/* codes for get_time */

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}			t_time_code;

/* philo status */

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED,
	FULL,
}			t_philo_status;

/* structs */

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int		philo_id;
	bool	full;
	long	meal_count;
	long	last_meal_time;
	t_fork	*first_fork;
	t_fork	*second_fork;
	pthread_t	thread_id;
	t_mtx	philo_mutex;
	t_mtx	eat_die_mutex;
	t_table	*table;
}				t_philo;

struct			s_table
{
	long	philos_num;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	num_limit_meals;
	long	start_sim;
	bool	all_philos_full;
	bool	end_sim;
	bool	all_threads_ready;
	long	threads_running_num;
	pthread_t	monitor;
	t_mtx	table_mutex;
	t_mtx	write_mutex;
	t_fork	*forks;
	t_philo	*philos;
};

/* prototypes */

/* utils */

// dinner.c //
void    think (t_philo *philo);
void    dinner_start(t_table *data);

// init.c //
void	init_table(t_table	*table);

// safe.c //
void	*safe_malloc(size_t bytes);
void	safe_mutex(t_mtx *mutex, t_opcode opcode);
void	safe_thread(pthread_t *thread, void *(*foo)(void *),
	void *data, t_opcode opcode);

// getters_setters.c // 

void    set_bool(t_mtx *mutex, bool *dest, bool value);
bool    get_bool(t_mtx *mutex, bool *value);
long    get_long(t_mtx *mutex, long *value);
void    set_long(t_mtx *mutex, long *dest, long value);
bool    sim_finished(t_table *data);

// synchro_utils.c //
void    wait_all_threads(t_table *data);
bool    all_threads_running(t_mtx *mutex, long *threads, long philo_num);
void    increase_long(t_mtx *mutex, long *value);
void    desync_philos(t_philo *philo);

// monitor.c //
void    *monitor_dinner(void *data);

// parse.c //
void	parse_input(t_table *table, char **argv);

// utils.c //
long	get_time(t_time_code time_code);
void	precise_usleep(long usec, t_table *data);
void	clean(t_table *data);
void	error_exit(const char	*error_msg);
void	debug(const char *msg);

// write.c //
void    write_status(t_philo_status status, t_philo *philo, bool debug);

#endif