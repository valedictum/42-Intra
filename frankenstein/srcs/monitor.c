/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:00:14 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 18:17:54 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Summary
	checks if a philosopher has died by comparing the time elalpsed since their
	last meal to the time to die, given as an argument when launching the
	program. Also uses a mutex to stop a philosopher from eating if they are in
	the process of dying.

	Inputs
	philo: a pointer to a t_philo struct that represents a philosopher.

	Outputs
	a bool, 'true' if the philosopher has died, otherwise 'false'.
*/
static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	safe_mutex(&philo->eat_die_mutex, LOCK);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex, \
	&philo->last_meal_time);
	time_to_die = philo->table->time_to_die / 1e3;
	if (elapsed > time_to_die)
	{
		safe_mutex(&philo->eat_die_mutex, UNLOCK);
		return (true);
	}
	safe_mutex(&philo->eat_die_mutex, UNLOCK);
	return (false);
}

/*
	Summary
	checks if all of the philosophers in the simulation have finished eating.
	only returns true if all philosophers are full.
*/
static bool	all_full(t_philo *philos, long num_of_philos)
{
	int	i;

	i = -1;
	while (++i < num_of_philos)
		if (philos[i].full == false)
			return (false);
	set_bool(&philos->table->table_mutex, &philos->table->all_philos_full, true);
	return (true);
}

/*
	Summary
	monitors philosophers during the dinner simulation and ends the simulation
	if a philosopher dies.
*/
void	*monitor_dinner(void *info)
{
	int		i;
	t_table	*table;

	table = (t_table *)info;
	while (!all_threads_running(&table->table_mutex, &table->threads_running_num, \
	table->philos_num))
		;
	while (!sim_finished(table))
	{
		i = -1;
		while (++i < table->philos_num && !sim_finished(table))
		{
			if (philo_died(table->philos + i))
			{
				set_bool(&table->table_mutex, &table->end_sim, true);
				write_status(DIED, table->philos + i, DEBUG_MODE);
			}
			else if (all_full(table->philos, table->philos_num))
			{
				set_bool(&table->table_mutex, &table->end_sim, true);
				write_status(FULL, table->philos + i, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}
