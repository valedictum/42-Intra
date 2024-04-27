/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:46:30 by sentry            #+#    #+#             */
/*   Updated: 2024/04/27 22:17:44 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	MY: init_philos and init_data - 2 functions

- 1 -
static void init_philos(t_data *data)
{
    int         i;
    t_philo     philo;

    i = 0;
    while (i < data->num_of_philos)
    {
        //philo = data->philos[i];
        philo->philo_num = i;
        philo->full = false;
        philo->eat_count = 0;
        philo->data = data;
        //philo_mutex;
        //philo_eat_die_mutex;
        //assign_forks;
        i++;
    }
}

- 2 -
void    init_data(t_data    *data)
{
    int i;

    i = 0;
    data->end_sim = false;
    data->all_philos_ready = false;
    data->all philos_full = false;
    data->num_of_threads = 0;
    data->philos = malloc(size_of(t_philo) * data->num_of_philos)
    //safe_mutex(data_mutex);
    //safe_mutex(write_mutex);
    data->forks = malloc(size_of(t_fork) * data->num_of_philos)
    //fork_mutex;
    //fork_num;
    init_philos(data);
}
*/

/*
    EVEN ODD fork assignment
*/
static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
    int philo_num;

    philo_num = philo->data->num_of_philos;
    
    philo->first_fork = &forks[(philo_position + 1) % philo_num];
    philo->second_fork = &forks[philo_position];
    if (philo->philo_id % 2 == 0)
    {
        philo->first_fork = &forks[philo_position];
        philo->second_fork = &forks[(philo_position + 1) % philo_num];
    }
}

static void init_philo(t_data  *data)
{
    int         i;
    t_philo     *philo;

    i = -1;
    while (i++ < data->num_of_philos)
    {
        philo = data->philos + 1;
        philo->philo_id = i + 1;
        philo->full = false;
        philo->meal_count = 0;
        philo->data = data;
        safe_mutex_handle(&philo->philo_mutex, INIT);
        // Ad hoc...i-position in the table
        assign_forks(philo, data->forks, i);
    }
}

void	init_data(t_data	*data)
{
    int i;

    i = -1;
	data->end_sim = false;
    data->all_threads_ready = false;
    data->threads_running_num = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->num_of_philos);
    data->forks = safe_malloc(sizeof(t_fork) * data->num_of_philos);
    safe_mutex_handle(&data->write_mutex, INIT);
    safe_mutex_handle(&data->table_mutex, INIT);
    while(++i < data->num_of_philos)
    {
        safe_mutex_handle(&data->forks[i].fork, INIT);
        data->forks[i].fork_id = i; // for debug
    }
    init_philo(data); // TO DO
}
