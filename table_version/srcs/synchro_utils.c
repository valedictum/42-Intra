/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:51:47 by sentry            #+#    #+#             */
/*   Updated: 2024/04/28 10:54:29 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    Wait for all threads to be ready,
    busy waiting (SPINLOCK) to synchronize philos start

    Use a getter function to read with no race 
    condition the variable
*/

void    wait_all_threads(t_table *table)
{
    while(!get_bool(&table->table_mutex, &table->all_threads_ready))
        ;
}

/*
    Synchronizes monitoring thread and philos. Monitor busy waits 
    until all threads are running (monitor thread can start only when all
    threads are ready).
    Monitor waits all threads are running the simulation before searching 
    deaths
*/

bool    all_threads_running(t_mtx *mutex, long *threads, long philo_num)
{
    bool    ret;

    ret = false;
    safe_mutex_handle(mutex, LOCK);
    if (*threads == philo_num)
        ret = true;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);

}

/*
    Increase threads running to synchro with the monitor i.e. when a philo enters 
    the loop, threads count ++
*/

void    increase_long(t_mtx *mutex, long *value)
{
    safe_mutex_handle(mutex, LOCK);
    (*value)++;
    safe_mutex_handle(mutex, UNLOCK);
}

/*
    Make the system fair
    
    Synchronize the philos to minimize resource contention and improve fairness
    1) if even, just 30ms (half the min value 60ms)
    2) if odd, start by thinking
*/

void    desynchronize_philos(t_philo *philo)
{
    if (philo->table->philos_num % 2 == 0)
    {
        if (philo->philo_id % 2 == 0)
        {
            precise_usleep(3e4, philo->table);
        }
        else
        {
            if (philo->philo_id % 2)
                thinking(philo, true);
        }
    }
}
