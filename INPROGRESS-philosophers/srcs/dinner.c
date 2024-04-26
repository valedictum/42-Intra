/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:23:01 by sentry            #+#    #+#             */
/*   Updated: 2024/04/26 11:34:32 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    1) Wait all philos, synchronise start
    2) Endless loop philo
*/

void    *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;

    wait_all_threads(); // TO DO
}



/*
	./philo 	5	800 	200 	200 	[5]
	1) If no meals, return -> [0]
	2) If only 1 philo ->ad hoc function
	3) Create all threads, all philos
    4) Create a monitor thread -> dead
    5) Synchronize the beginning of the sim
        pthread_create->philo starts running!
        every philo start simultaneously
    6) JOIN everyone
*/

void    dinner_start (t_data *data)
{
    int     i;

    i = -1;
    if (data->num_limit_meals == 0)
        return ; // back to main, clean
    else if (data->num_of_philos == 1)
        ;// TO DO
    else
    {
        while (i++ < data->num_of_philos)
            safe_thread_handle(&data->philos[i].thread_id, dinner_simulation,
                &data->philos[i], CREATE);

}