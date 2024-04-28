/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:54:55 by sentry            #+#    #+#             */
/*   Updated: 2024/04/28 11:01:42 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

/*
                    t_die
    last_meal----------------------last_meal

    Maybe philo full?
    1) Check if the philo is full, he has already finished his own simulation. 
    Monitor does not care. Return.
 
    2) Check if the philo is died reading in a thread safe manner the last_meal 

    time_to_die / 1e3 - need to convert back from micro to milli t_to_die
*/

static bool  philo_died(t_philo *philo)
{
    long    elapsed;
    long    t_to_die;

    if(get_bool(&philo->philo_mutex, &philo->full))
        return (false);
    elapsed = get_time(MILLISECOND) - get_long(&philo->philo_mutex,
        &philo->last_meal_time);
    t_to_die = philo->table->time_to_die / 1e3;
    if (elapsed >t_to_die)
        return (true);
    return (false);
}

/*
    THREAD continuosly monitoring death philos
    Two conditions to finish

    1) if philo is death, set the flag end simulation to true and return
    2) All philos are full, end_simulation will be turned on by the main
    (monitor) thread in this case, when all the philos are JOINED
        end_simulation is changed by the main thread | monitor💡
*/
void    *monitor_dinner(void *data)
{
    int         i;
    t_table     *table;

    table = (t_table *)data;
    while (!all_threads_running(&table->table_mutex, &table->threads_running_num,
            table->philos_num))
        ;
    while(!sim_finished(table))
    {
        i = -1;
        while (++i < table->philos_num && !sim_finished(table))
        {
            if (philo_died(table->philos + i)) // TO DO
            {
                set_bool(&table->table_mutex, &table->end_sim, true);
                write_status(DIED, table->philos + i, DEBUG_MODE);
            }
        }
    }
    return (NULL);
}
