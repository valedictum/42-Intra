/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:22:39 by sasharma          #+#    #+#             */
/*   Updated: 2024/01/20 11:22:43 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_is_dead(t_philo *cur_philo)
{
	if ((get_elapsed(cur_philo->rules) - cur_philo->last_eat_time) \
			> cur_philo->rules->time_to_die)
		return (1);
	return (0);
}

int	a_philo_is_dead(t_philo *cur_philo)
{
	int	i;
	int	n;

	i = 0;
	n = cur_philo->rules->philo_num;
	while (i < n)
	{
		if (philo_is_dead(cur_philo))
			return (1);
		cur_philo = cur_philo->right;
		i++;
	}
	return (0);
}

int	monitor_do(t_philo *cur_philo)
{
	print_status(cur_philo, 'D');
	ft_stop_routine(cur_philo);
	if (cur_philo->id % 2 == 0)
		pthread_mutex_unlock(&cur_philo->my_fork);
	else
		pthread_mutex_unlock(&cur_philo->right->my_fork);
	return (1);
}

void	*ft_run_monitor(void *m_philo)
{
	t_philo	*cur_philo;
	int		i;

	cur_philo = (t_philo *)m_philo;
	i = 0;
	while (cur_philo->rules->stop_flag == 0)
	{
		i = 0;
		while (i < cur_philo->rules->philo_num)
		{
			if (philo_is_dead(cur_philo) && cur_philo->rules->stop_flag == 0)
				if (monitor_do(cur_philo))
					return (NULL);
			cur_philo = cur_philo->right;
			i++;
		}
		if (everyone_is_full(cur_philo, cur_philo->rules->philo_num))
		{
			ft_stop_routine(cur_philo);
			print_status(cur_philo, 'B');
			return (NULL);
		}
	}
	return (NULL);
}
