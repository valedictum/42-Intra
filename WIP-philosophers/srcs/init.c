/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 07:46:30 by sentry            #+#    #+#             */
/*   Updated: 2024/03/06 21:12:38 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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