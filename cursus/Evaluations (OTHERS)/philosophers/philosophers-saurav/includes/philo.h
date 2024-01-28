/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:38:10 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/19 09:25:11 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int				id;
	int				meals_to_full;
	int				is_full;
	long long		last_eat_time;
	long long		last_sleep_time;
	char			status;
	pthread_t		thread_id;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	is_alive;
	struct s_philo	*left;
	struct s_philo	*right;
	struct s_state	*rules;
}	t_philo;

typedef struct s_state
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meal_num_req;
	int				overall_state;
	int				stop_flag;
	long long		start_time;
	pthread_mutex_t	print_mutex_rule;
}	t_state;

//initilize.c
void	initilize_struct(int argc, char **argv, t_state *philo_state);

//utils.c
int		timefunction(void);
int		get_elapsed(t_state *rule_state);
void	ft_printbr(void);
void	ft_error(char *error_msg);
long	ft_atoi(const char *str);

//philosopher_utils.c
void	init_philosophers(t_state *rule_state, t_philo **philosophers);
void	set_new_philo(t_philo *m_philo, t_state *rule_state, int i);

//philosopher_routine.c
void	run_routine(t_philo *m_philo);
void	*philosopher_routine(void *m_philo);
void	*ft_run_monitor(void *m_philo);

//linkedlsit_util.c
void	ft_free_list(t_philo *first);
void	ft_exit(t_philo **m_philosophers, char *error_msg);
void	ft_lstadd_back(t_philo **lst, t_philo *new_philo);
t_philo	*ft_lstlast(t_philo *lst);

//philosopher_utils.c
void	print_philo_state(t_philo *m_philo);
void	print_philosophers(t_philo **m_philosophers, int philo_count);
void	init_philosophers(t_state *m_state, t_philo **m_philosophers);

//monitor_routines.c
void	*ft_run_monitor(void *m_philo);
int		monitor_do(t_philo *cur_philo);
int		a_philo_is_dead(t_philo *cur_philo);
int		philo_is_dead(t_philo *cur_philo);
//Routine utils
void	print_status(t_philo *m_philo, char status_type);
void	ft_stop_routine(t_philo *m_philo);
int		noone_is_dead(t_philo *m_philo, int n);
int		everyone_is_full(t_philo *m_philo, int n);
int		m_round(int number);
#endif
