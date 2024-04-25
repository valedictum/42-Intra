/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchro.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:48:29 by tday              #+#    #+#             */
/*   Updated: 2023/12/23 19:46:46 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Summary
	waits for all threads to be ready by using spinlock to synchronise threads
	before continuing execution.
*/
void	wait_all_threads(t_data *data)
{
	while (!get_bool(&data->data_mutex, &data->all_threads_ready))
		;
}

/*
	Summary
	check if all threads are running by comparing the value of the variable
	'threads' to the total number of philosophers (each should have it's own
	thread).

	Inputs
	mutex: a pointer to a mutex.
	threads: a vaiable that stores the number of running threads.
	num_of_philos: the total number of threads/philosophers.

	Output
	a bool indicating if all threads are running or not.
*/
bool	all_threads_running(t_mutex *mutex, long *threads, long num_of_philos)
{
	bool	result;

	result = false;
	safe_mutex(mutex, LOCK);
	if (*threads == num_of_philos)
		result = true;
	safe_mutex(mutex, UNLOCK);
	return (result);
}

/*
	Summary
	increments the value of a long integer in a thread-safe manner by using a
	mutex lock.

	Inputs
	mutex: a pointer to a mutex which blocks other threads from accessing the
		variable until it has been unlocked at the end of the function.
	value: a pointer to the long variable tht needs to be incremented.

	Output
	none.
*/
void	increase_long(t_mutex *mutex, long *value)
{
	safe_mutex(mutex, LOCK);
	(*value)++;
	safe_mutex(mutex, UNLOCK);
}

/*
	Summary
	introduces a delay in the execution of certain philosophers.
	it checks if the total number of philosophers is even or odd as, if there is
	an even number, the even numbered philosophers can eat while the odd numbered
	ones sleep and so long. if the total number of philosophers is odd however,
	more nuance is needed as the first and last philosophers will fight for a
	fork if they try to eat at the same time.
	for an even number of philosophers, sleeping the even numbered philosophers
	will allow the odd numbered ones to grab forks and eat first avoiding
	contention of forks at the start of the dinner simulation, they will then
	alternate for the rest of the simulation.

*/
void	desync_philos(t_philo *philo)
{
	if (philo->data->num_of_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			precise_usleep(3e4, philo->data);
	}
	else
	{
		if (philo->id % 2 == 0)
			think(philo);
	}
}
