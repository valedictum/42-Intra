/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:46:30 by sentry            #+#    #+#             */
/*   Updated: 2024/05/05 09:44:18 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    Every philo is assigned a first and second fork. It is
    EVEN and ODD fork assignment (not L and R) to avoid deadlock.

    Using i from the caller loop as a position value, given that 
    the philo ID is i + 1 this makes, the code more readable
*/

static void assign_forks(t_philo *philo, t_fork *forks_arr, int philo_position)
{
    int philo_count;

    philo_count = philo->data->philo_count;
    /*if (philo->philo_id % 2 != 0)
    {
        philo->first_fork = &forks_arr[(philo_position + 1) % philo_count];
        philo->second_fork = &forks_arr[philo_position];
    }
    */
    //OG version - START
    philo->first_fork = &forks_arr[(philo_position + 1) % philo_count];
    philo->second_fork = &forks_arr[philo_position];
    //END
    if (philo->philo_id % 2 == 0)
    {
        philo->first_fork = &forks_arr[philo_position];
        philo->second_fork = &forks_arr[(philo_position + 1) % philo_count];
    }
}

/*
    Init all philos with all necessary fields
*/

static void init_philo(t_data *data)
{
    int         i;
    t_philo     *philo;

    i = -1;
    //i = 0; //in Thuy's
    //while (i < data->philo_count - 1) // in Thuy's
    while (++i < data->philo_count)
    {
        philo = data->philos_arr + i;
        philo->philo_id = i + 1;
        philo->full = false;
        philo->meal_count = 0;
        philo->data = data;
        safe_mutex(&philo->philo_mutex, INIT);
        safe_mutex(&philo->eat_die_mutex, INIT); // Added Tas
        printf("philo %d created\n", data->philos_arr[i].philo_id); // print philo_creation with philo_id
        assign_forks(philo, data->forks_arr, i);
        //i++; // In Thuy's
    }
}

/*
    Init table data with all necessary fields (controls on errors 
    embedded in safe functions).
    Every fork gets an ID value, which is useful for debugging: you can
    see these values during DEBUG_MODE = 1.
*/

void	init_data(t_data	*data)
{
    int i;

    i = -1;
	data->sim_finish_time = false;
    data->all_threads_ready = false;
    data->threads_running_count = 0;
    data->philos_arr = safe_malloc(data->philo_count * sizeof(t_philo));
    safe_mutex(&data->access_mutex, INIT);
    safe_mutex(&data->write_mutex, INIT);
    data->forks_arr = safe_malloc(data->philo_count * sizeof(t_fork));
    while (++i < data->philo_count)
    {
        safe_mutex(&data->forks_arr[i].fork_mutex, INIT);
        data->forks_arr[i].fork_id = i;
        printf("fork %d created\n", data->forks_arr[i].fork_id); // print fork_creation with fork_id
    }
    init_philo(data);
}
