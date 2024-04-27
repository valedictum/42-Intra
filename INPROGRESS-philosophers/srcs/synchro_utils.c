/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:51:47 by sentry            #+#    #+#             */
/*   Updated: 2024/04/27 23:31:40 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    SPINLOCK to synchronize philos start
*/

void    wait_all_threads(t_data *data)
{
    while(!get_bool(&data->table_mutex, &data->all_threads_ready))
        ;
}

/*
    Monitor busy waits until all threads are running
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
    Increase threads running to synchro with the monitor
*/

void    increase_long(t_mtx *mutex, long *value)
{
    safe_mutex_handle(mutex, LOCK);
    (*value)++;
    safe_mutex_handle(mutex, UNLOCK);
}

/*
    Make the system fair
*/

void    desynchronize_philos(t_philo *philo)
{
    if (philo->data->num_of_philos % 2 == 0)
    {
        if (philo->philo_id % 2 == 0)
        {
            precise_usleep(3e4, philo->data);
        }
        else
        {
            if (philo->philo_id % 2)
                thinking(philo, true);
        }
    }
}
