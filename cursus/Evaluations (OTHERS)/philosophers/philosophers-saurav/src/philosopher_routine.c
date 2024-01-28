/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:23:18 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/20 11:23:20 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	run_routine(t_philo *m_philo)
{
	int	n;
	int	i;

	n = m_philo->rules->philo_num;
	i = 0;
	while (i < n)
	{
		if (pthread_create(&(m_philo->thread_id), NULL, \
					philosopher_routine, m_philo) != 0)
		{
			print_status(m_philo, 'X');
			break ;
		}
		m_philo = m_philo->right;
		i++;
	}
}

void	think_routine(t_philo *cur_philo)
{
	if (cur_philo->id % 2 == 1)
	{
		pthread_mutex_lock(&cur_philo->my_fork);
		if (cur_philo->rules->stop_flag == 0)
			print_status(cur_philo, 'F');
		pthread_mutex_lock(&cur_philo->right->my_fork);
		if (cur_philo->rules->stop_flag == 0)
			print_status(cur_philo, 'F');
	}
	else
	{
		pthread_mutex_lock(&cur_philo->right->my_fork);
		if (cur_philo->rules->stop_flag == 0)
			print_status(cur_philo, 'F');
		pthread_mutex_lock(&cur_philo->my_fork);
		if (cur_philo->rules->stop_flag == 0)
			print_status(cur_philo, 'F');
	}
	if (cur_philo->rules->stop_flag == 0)
	{
		print_status(cur_philo, 'E');
		cur_philo->status = 'E';
	}
}

void	eat_routine(t_philo *cur_philo)
{
	int	i;
	int	m;

	pthread_mutex_lock(&cur_philo->is_alive);
	cur_philo->meals_to_full = cur_philo->meals_to_full - 1;
	if (cur_philo->meals_to_full == 0)
		cur_philo->is_full = 1;
	cur_philo->last_eat_time = m_round(timefunction() \
			- cur_philo->rules->start_time);
	i = 0;
	m = cur_philo->last_eat_time + cur_philo->rules->time_to_eat - 1;
	while (i < m)
	{
		usleep(1000);
		i = get_elapsed(cur_philo->rules);
	}
	pthread_mutex_unlock(&cur_philo->my_fork);
	pthread_mutex_unlock(&cur_philo->right->my_fork);
	if (cur_philo->rules->stop_flag == 0)
		print_status(cur_philo, 'S');
	cur_philo->status = 'S';
	pthread_mutex_unlock(&cur_philo->is_alive);
}

void	sleep_routine(t_philo *cur_philo)
{
	cur_philo->last_sleep_time = get_elapsed(cur_philo->rules);
	usleep((cur_philo->rules->time_to_sleep) * 1000);
	if (cur_philo->rules->stop_flag == 0)
		print_status(cur_philo, 'T');
	cur_philo->status = 'T';
}

void	*philosopher_routine(void *m_philo)
{
	t_philo	*cur_philo;
	int		n;

	cur_philo = (t_philo *)m_philo;
	n = cur_philo->rules->philo_num;
	while (cur_philo->rules->stop_flag == 0 && cur_philo->is_full == 0)
	{
		if (everyone_is_full(cur_philo, n) || a_philo_is_dead(cur_philo)
			|| cur_philo->rules->stop_flag == 1)
			return (print_status(cur_philo, 'A'), NULL);
		if (cur_philo->status == 'T' && cur_philo->rules->stop_flag == 0)
			think_routine(cur_philo);
		if (everyone_is_full(cur_philo, n) || a_philo_is_dead(cur_philo)
			|| cur_philo->rules->stop_flag == 1)
			return (print_status(cur_philo, 'A'), NULL);
		if (cur_philo->status == 'E' && cur_philo->rules->stop_flag == 0)
			eat_routine(cur_philo);
		if (everyone_is_full(cur_philo, n) || a_philo_is_dead(cur_philo)
			|| cur_philo->rules->stop_flag == 1)
			return (print_status(cur_philo, 'A'), NULL);
		if (cur_philo->status == 'S' && cur_philo->rules->stop_flag == 0)
			sleep_routine(cur_philo);
	}
	return (NULL);
}
