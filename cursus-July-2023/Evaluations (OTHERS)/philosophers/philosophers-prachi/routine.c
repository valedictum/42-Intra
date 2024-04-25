/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:50:28 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 20:02:45 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_data_philo	*philo;

	philo = (t_data_philo *)arg;
	if (philo->philo_id % 2 == 0)
		new_sleep(philo->time_to_eat * 0.9);
	while (alive_check(philo))
	{
		if (meal(philo) == -1)
			return (NULL);
		if (!alive_check(philo))
			return (NULL);
		print_info(philo, SLEEP);
		new_sleep(philo->time_to_sleep);
		print_info(philo, THINK);
	}
	return (NULL);
}

int	acquire_forks(t_data_philo *philo)
{
	if (!alive_check(philo))
		return (-1);
	pthread_mutex_lock(philo->left_fork);
	print_info(philo, TAKE_L_FORK);
	if (!alive_check(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	if (philo->right_fork == NULL)
	{
		pthread_mutex_unlock(philo->left_fork);
		new_sleep(philo->time_to_die * 1.1);
		return (-1);
	}
	pthread_mutex_lock(philo->right_fork);
	print_info(philo, TAKE_R_FORK);
	print_info(philo, EAT);
	if (!alive_check(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (-1);
	}
	return (0);
}

void	eat_and_release_forks(t_data_philo *philo)
{
	update_meal_status(philo);
	if (!alive_check(philo))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	new_sleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	meal(t_data_philo *philo)
{
	if (acquire_forks(philo) == -1)
	{
		return (-1);
	}
	eat_and_release_forks(philo);
	return (0);
}

void	update_meal_status(t_data_philo *philo)
{
	pthread_mutex_lock(philo->priv_lock);
	philo->last_meal_time = get_time_now();
	pthread_mutex_unlock(philo->priv_lock);
	if (philo->eat_x_times != 0)
	{
		if (++philo-> ate_x_times == philo->eat_x_times)
		{
			pthread_mutex_lock(philo->main_lock);
			*philo->already_ate_max += 1;
			pthread_mutex_unlock(philo->main_lock);
		}
	}
}
