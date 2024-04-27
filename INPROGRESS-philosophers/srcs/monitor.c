/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:54:55 by sentry            #+#    #+#             */
/*   Updated: 2024/04/27 23:36:12 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

/*
                    t_die
    last_meal----------------------last_meal

    Maybe philo full?
*/

static bool  philo_died(t_philo *philo)
{
    long    elapsed;
    long    t_to_die;

    if(get_bool(&philo->philo_mutex, &philo->full))
        return (false);
    elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex, &philo->last_meal_time);
    // convert back to milliseconds
    t_to_die = philo->data->time_to_die / 1e3;

    if (elapsed >t_to_die) //t_to_die has to be converted back to ms
        return (true);
    return (false);
}

void    *monitor_dinner(void *info)
{
    int        i;
    t_data  *data;

    data = (t_data *)info;
    // Make sure all philo running
    // Spinlock til all threads run
    while (!all_threads_running(&data->table_mutex, &data->threads_running_num,
            data->num_of_philos))
        ;
    while(!sim_finished(data))
    {
        i = -1;
        while (++i < data->num_of_philos && !sim_finished(data))
        {
            if (philo_died(data->philos + 1)) // TO DO
            {
                set_bool(&data->table_mutex, &data->end_sim, true);
                write_status(DIED, data->philos + 1, DEBUG_MODE);
            }
        }
    }
    return (NULL);
}
