/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:42:40 by tday              #+#    #+#             */
/*   Updated: 2023/12/24 14:20:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthrd;
typedef struct s_data	t_data;

/* int values */

#define INT_MIN	-2147483648
#define INT_MAX	2147483647

/* text colours */

#define DEF		"\033[0m"
#define GRAY	"\033[1;30m"
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MGNTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define WHITE	"\033[1;37m"

/* write function debug macro */

#define DEBUG_MODE	0

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
	t_mutex	fork;
	int		fork_id;
}				t_fork;

typedef struct s_philo
{
	int		id;
	bool	full;
	long	meals_count;
	long	last_meal_time;
	t_fork	*first_fork;
	t_fork	*second_fork;
	t_pthrd	thread_id;
	t_mutex	philo_mutex;
	t_mutex	eat_die_mutex;
	t_data	*data;
}				t_philo;

struct			s_data
{
	long	num_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_limit;
	long	start_of_sim;
	bool	all_philos_full;
	bool	end_sim;
	bool	all_threads_ready;
	long	num_threads_running;
	t_pthrd	monitor;
	t_mutex	data_mutex;
	t_mutex	write_mutex;
	t_fork	*forks;
	t_philo	*philos;
};

/* prototypes */

/* utils */

void	error_exit(const char *error);
long	get_time(t_time_code time_code);
void	precise_usleep(long usec, t_data *data);
void	clean(t_data *data);

/* safe_functions */

void	*safe_malloc(size_t bytes);
void	safe_mutex(t_mutex *mutex, t_opcode opcode);
void	safe_thread(pthread_t *thread, void *(*foo)(void *), void *data, \
		t_opcode opcode);

/* inputs */

void	parse_input(t_data *data, char *argv[]);

/* init */

void	data_init(t_data *data);

/* dinner */

void	dinner_start(t_data *data);
void	think(t_philo *philo);

/* set_and_get */

void	set_bool(t_mutex *mutex, bool *dest, bool value);
bool	get_bool(t_mutex *mutex, bool *value);
void	set_long(t_mutex *mutex, long *dest, long value);
long	get_long(t_mutex *mutex, long *value);
bool	simulation_finished(t_data *data);

/* synchro */

void	wait_all_threads(t_data *data);
bool	all_threads_running(t_mutex *mutex, long *threads, long num_of_philos);
void	increase_long(t_mutex *mutex, long *value);
void	desync_philos(t_philo *philo);

/* write */

void	write_status(t_philo_status status, t_philo *philo, bool debug);

/* monitor */
void	*monitor_dinner(void *info);