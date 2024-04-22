/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:09:44 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 20:26:04 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EAT	"\033[33mis eating \033[0m"
# define SLEEP "\033[1;33mis sleeping \033[0m"
# define THINK "\033[90mis thinking \033[0m"
# define TAKE_L_FORK	"\033[92mhas taken left fork \033[0m"
# define TAKE_R_FORK	"\033[92mhas taken right fork \033[0m"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data_philo
{
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				ate_x_times;
	int				*already_ate_max;
	long int		last_meal_time;
	long int		*start_time;
	int				stop;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*main_lock;
	pthread_mutex_t	*priv_lock;
	pthread_mutex_t	*write_message;
}				t_data_philo;

typedef struct s_table
{
	int				philos_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_x_times;
	int				already_ate_max;
	pthread_t		*threads;
	t_data_philo	*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_message;
	long int		start_time;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	*priv_lock;
}				t_table;

int				set_check_args(t_table *table, int argc, char **argv);
void			set_arguments(t_table *table, int argc, char **argv);
int				meal_control(t_table *table, t_data_philo *philo);
void			control(t_table *table, t_data_philo *philo);
void			destroy(t_table *table);
void			free_all(t_table *table);
int				error_message_args(t_table *table);
void			print_info(t_data_philo *philo, char *action);
int				init_all(t_table *table);
void			init_philo(t_table *table, t_data_philo *philo);
int				init_mutex(t_table *table);
int				init_threads(t_table *table);
void			init_philo_attributes(t_table *table,
					t_data_philo *philo, int i);
void			*philo_routine(void *arg);
void			update_meal_status(t_data_philo *philo);
int				meal(t_data_philo	*philo);
int				alive_check(t_data_philo *philo);
void			eat_and_release_forks(t_data_philo *philo);
int				acquire_forks(t_data_philo *philo);
long int		get_time_now(void);
void			new_sleep(int mil_sec);
int				wait_threads(t_table *table);
int				digit_check(char *c);
int				is_int(char *str);
int				atoi_philo(char *str);

#endif
