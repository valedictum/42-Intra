/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:17:41 by tday              #+#    #+#             */
/*   Updated: 2023/12/23 21:39:21 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
Summary
assigns the correct forks to each philosopher based on their position and id.
if the philosopher has an even id number, the first and second forks are
switched to avoid a deadlock.

Inputs
philo: a pointer to a philosopher struct.
forks: a pointer to an array representing the forks.
position: an int representing the position of the philosopher at the table.

Outputs
none. the function modifies the first_fork and second_fork fields of the philo
struct.
*/
static void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int	number_of_philos;

	number_of_philos = philo->data->num_of_philos;
	philo->first_fork = &forks[(position + 1) % number_of_philos];
	philo->second_fork = &forks[position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[position];
		philo->second_fork = &forks[(position + 1) % number_of_philos];
	}
}

/*
Summary
initialises the philosophers by setting their initial state and assigning the
correct forks and IDs.

Inputs
data: a pointer to a struct that contains information about the philosophers.

Outputs
none. the function modifies the fields of the 'data' struct.
*/
static void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->num_of_philos)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_count = 0;
		philo->data = data;
		safe_mutex(&philo->philo_mutex, INIT);
		safe_mutex(&philo->eat_die_mutex, INIT);
		assign_forks(philo, data->forks, i);
	}
}

/*
Summary
initialises the data, philos, and forks structs.

Inputs
data: a pointer to a struct that contains information about the philosophers.

Outputs
none. the function modifies the fields of the 'data' struct.
*/
void	data_init(t_data *data)
{
	int	i;

	i = -1;
	data->end_sim = false;
	data->all_threads_ready = false;
	data->all_philos_full = false;
	data->num_threads_running = 0;
	data->philos = safe_malloc(sizeof(t_philo) * data->num_of_philos);
	safe_mutex(&data->data_mutex, INIT);
	safe_mutex(&data->write_mutex, INIT);
	data->forks = safe_malloc(sizeof(t_fork) * data->num_of_philos);
	while (++i < data ->num_of_philos)
	{
		safe_mutex(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
	philo_init(data);
}
