/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:23:01 by sentry            #+#    #+#             */
/*   Updated: 2024/04/27 09:58:22 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void thinking (t_philo *philo)
{
    write_status(THINKING, philo, DEBUG_MODE);
}

/*
    EAT ROUTINE
    1) Grab forks : here first and second fork are handy (don't worry about R and L)
    2) Eat: write eat, update last meal, update meal_count
        eventually bool full
    3) Release forks
*/

static void    eat(t_philo *philo)
{
    // 1)
    safe_mutex_handle(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex_handle(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);

    // 2) Actual eating
    set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
    philo->meal_count++;
    write_status(EATING, philo, DEBUG_MODE);
    precise_usleep(philo->data->time_to_eat, philo->data);
    if (philo->data->num_limit_meals > 0 
        && philo->meal_count == philo->data->num_limit_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);
    
    // 3)
    safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
    safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
}

/*
    1) Wait all philos, synchronise start
    2) Endless loop philo
*/

void    *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    // spinlock
    wait_all_threads(philo->data);
    // set last meal time
    while(!sim_finished(philo->data))
    {
        // 1) Am I full?
        if(philo->full) // TO DO thread safe?
            break ;
        // 2) Eat
        eat(philo);
        // 3) Sleep -> write_status & precise usleep
        write_status(SLEEPING, philo, DEBUG_MODE);
        precise_usleep(philo->data->time_to_sleep, philo->data);
        // 4) Think
        thinking(philo); // TO DO
    }
    return (NULL);
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

void    start_dinner(t_data *data)
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
    // start of simulation
    data->start_sim = get_time(MILLISECOND);
    // now all threads are ready!
    set_bool(&data->table_mutex, &data->all_threads_ready, true);
    // Wait for everyone
    i = -1;
    while (i++ < data->num_of_philos)
        safe_thread_handle(&data->philos[i].thread_id, NULL, NULL, JOIN);
    // If we manage to reach this line, all philos are full! 
}