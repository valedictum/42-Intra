/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:33:55 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 19:34:40 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	meal_control(t_table *table, t_data_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&table -> main_lock);
	if (table -> already_ate_max == table -> philos_num)
	{
		printf("\033[0;36mphilosophers finished eating\n\033[0m");
		while (++i < table -> philos_num)
			philo[i].stop = 1;
		pthread_mutex_unlock(&table -> main_lock);
		return (-1);
	}
	pthread_mutex_unlock(&table -> main_lock);
	return (0);
}

void	control(t_table *table, t_data_philo *philo)
{
	int				i;

	i = -1;
	while (++i < table -> philos_num)
	{
		pthread_mutex_lock(&table -> priv_lock[i]);
		if (get_time_now() - philo[i].last_meal_time >= table -> time_to_die)
		{
			pthread_mutex_unlock(&table -> priv_lock[i]);
			pthread_mutex_lock(&table -> main_lock);
			printf("[%d] Philo: %d %s\n", \
				(int)(get_time_now() - table -> start_time),
				i + 1, "\033[31mdied\033[0m");
			i = -1;
			while (++i < table -> philos_num)
				philo[i].stop = 1;
			pthread_mutex_unlock(&table -> main_lock);
			return ;
		}
		pthread_mutex_unlock(&table -> priv_lock[i]);
		if (meal_control(table, philo) == -1)
			return ;
		if (i + 1 == table -> philos_num)
			i = -1;
	}
}
