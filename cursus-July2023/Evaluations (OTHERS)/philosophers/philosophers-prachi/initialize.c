/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:44:44 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 19:50:21 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_all(t_table *table)
{
	table -> philos = malloc(sizeof(t_data_philo) * table -> philos_num);
	if (table -> philos == NULL)
	{
		free_all(table);
		return (-1);
	}
	table -> threads = malloc(sizeof(pthread_t) * table -> philos_num);
	if (table -> threads == NULL)
	{
		free_all(table);
		return (-1);
	}
	if (init_mutex(table) == -1)
		return (-1);
	table -> already_ate_max = 0;
	init_philo(table, table -> philos);
	init_threads(table);
	return (0);
}

void	init_philo_attributes(t_table *table, t_data_philo *philo, int i)
{
	philo[i].philo_id = i + 1;
	philo[i].start_time = &table -> start_time;
	philo[i].left_fork = &table -> forks[i];
	if (table -> philos_num > 1)
		philo[i].right_fork = &table -> forks[(i + 1) % table -> philos_num];
	else
		philo[i].right_fork = NULL;
	philo[i].ate_x_times = 0;
	philo[i].eat_x_times = table -> eat_x_times;
	philo[i].last_meal_time = get_time_now();
	philo[i].stop = 0;
	philo[i].time_to_die = table -> time_to_die;
	philo[i].time_to_eat = table -> time_to_eat;
	philo[i].time_to_sleep = table -> time_to_sleep;
	philo[i].already_ate_max = &table -> already_ate_max;
	philo[i].main_lock = &table -> main_lock;
	philo[i].priv_lock = &table -> priv_lock[i];
	philo[i].write_message = &table -> write_message;
}

void	init_philo(t_table *table, t_data_philo *philo)
{
	int	i;

	i = 0;
	while (i < table -> philos_num)
	{
		init_philo_attributes(table, philo, i);
		i++;
	}
}

int	init_mutex(t_table *table)
{
	int		i;

	i = 0;
	table -> forks = malloc(table -> philos_num * sizeof(pthread_mutex_t));
	if (!table -> forks)
	{
		free_all(table);
		return (-1);
	}
	table -> priv_lock = malloc(table -> philos_num * sizeof(pthread_mutex_t));
	if (!table -> priv_lock)
	{
		free_all(table);
		return (-1);
	}
	while (i < table -> philos_num)
	{
		pthread_mutex_init(&table -> forks[i], NULL);
		pthread_mutex_init(&table -> priv_lock[i], NULL);
		i++;
	}
	pthread_mutex_init(&table -> main_lock, NULL);
	pthread_mutex_init(&table -> write_message, NULL);
	return (0);
}

int	init_threads(t_table *table)
{
	int	i;

	i = 0;
	table -> start_time = get_time_now();
	while (i < table -> philos_num)
	{
		pthread_create(&table -> threads[i], NULL,
			&philo_routine, &table -> philos[i]);
		i++;
	}
	return (1);
}
