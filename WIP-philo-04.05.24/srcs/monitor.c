/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:54:55 by sentry            #+#    #+#             */
/*   Updated: 2024/05/05 22:28:18 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
                    t_die
    last_meal----------------------last_meal

    Maybe philo full?
    1) Check if the philo is full, he has already finished his own simulation. 
    Monitor does not care. Return.
 
    2) Check if the philo is died reading in a thread safe manner the last_meal 

    time_to_die / 1e3 - need to convert back from micro to milli t_to_die
*/

static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	time_to_die;

	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	safe_mutex(&philo->eat_die_mutex, LOCK);
	elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex,
			&philo->last_meal_time);
	time_to_die = philo->data->time_to_die / 1e3;
	if (elapsed > time_to_die)
	{
		write_status(DIED, philo, DEBUG_MODE);
		safe_mutex(&philo->eat_die_mutex, UNLOCK);
		return (true);
	}
	safe_mutex(&philo->eat_die_mutex, UNLOCK);
	return (false);
}

static bool	all_full(t_philo *philos, long philo_count)
{
	int	i;

	i = -1;
	while (++i < philo_count)
		if (philos[i].full == false)
			return (false);
	set_bool(&philos->data->access_mutex, &philos->data->all_philos_full, true);
	return (true);
}

/*
    THREAD continuosly monitoring death philos
    Two conditions to finish

    1) if philo is death, set the flag end simulation to true and return
    2) All philos are full, end_simulation will be turned on by the main
    (monitor) thread in this case, when all the philos are JOINED
        end_simulation is changed by the main thread | monitor💡
*/
void	*monitor_dinner(void *ph_data)
{
	int		i;
	t_data	*data;

	data = (t_data *)ph_data;
	while (!all_threads_running(&data->access_mutex,
			&data->threads_running_count, data->philo_count))
		;
	while (!sim_finished(data))
	{
		i = -1;
		while (++i < data->philo_count && !sim_finished(data))
		{
			if (philo_died(data->philos_arr + i))
				set_bool(&data->access_mutex, &data->sim_finish_time, true);
			else if (all_full(data->philos_arr, data->philo_count))
			{
				set_bool(&data->access_mutex, &data->sim_finish_time, true);
				write_status(FULL, data->philos_arr + i, DEBUG_MODE);
			}
		}
	}
	return (NULL);
}
