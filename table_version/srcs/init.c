/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:46:30 by sentry            #+#    #+#             */
/*   Updated: 2024/04/28 10:37:39 by sentry           ###   ########.fr       */
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
    Every philo is assigned a first and second fork. It is
    EVEN and ODD fork assignment (not L and R) to avoid deadlock.

    Using i from the caller loop as a position value, given that 
    the philo ID is i + 1 this makes, the code more readable
*/

static void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
    int philo_num;

    philo_num = philo->table->philos_num;
    philo->first_fork = &forks[(philo_position + 1) % philo_num];
    philo->second_fork = &forks[philo_position];
    if (philo->philo_id % 2 == 0)
    {
        philo->first_fork = &forks[philo_position];
        philo->second_fork = &forks[(philo_position + 1) % philo_num];
    }
}

/*
    Init all philos with all necessary fields
*/

static void init_philo(t_table  *table)
{
    int         i;
    t_philo     *philo;

    i = -1;
    while (i++ < table->philos_num)
    {
        philo = table->philos + 1;
        philo->philo_id = i + 1;
        philo->full = false;
        philo->meal_count = 0;
        safe_mutex_handle(&philo->philo_mutex, INIT);
        philo->table = table;
        assign_forks(philo, table->forks, i);
    }
}

/*
    Init table data with all necessary fields (controls on errors 
    embedded in safe functions).
    Every fork gets an ID value, which is useful for debugging: you can
    see these values during DEBUG_MODE = 1.
*/

void	init_table(t_table	*table)
{
    int i;

    i = -1;
	table->end_sim = false;
    table->all_threads_ready = false;
    table->threads_running_num = 0;
    table->philos = safe_malloc(table->philos_num * sizeof(t_philo));
	table->forks = safe_malloc(table->philos_num * sizeof(t_fork));
    safe_mutex_handle(&table->write_mutex, INIT);
    safe_mutex_handle(&table->table_mutex, INIT);
    while (++i < table->philos_num)
    {
        safe_mutex_handle(&table->forks[i].fork, INIT);
        table->forks[i].fork_id = i;
    }
    init_philo(table);
}
