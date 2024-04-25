/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:24 by tday              #+#    #+#             */
/*   Updated: 2023/12/23 21:52:20 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Summary
	the process for a philosopher to eat during the dinner simulation.

	1. grab forks
	2. eat (update last meal time, update meals count, output eating status,
	usleep for time to eat, set bool full to true in philosopher is full)
	3. release forks
*/
static void	eat(t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->second_fork->fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->eat_die_mutex, LOCK);
	set_long(&philo->philo_mutex, &philo->last_meal_time, \
	get_time(MILLISECOND));
	philo->meals_count++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->meals_limit > 0 && \
	philo->meals_count == philo->data->meals_limit)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex(&philo->first_fork->fork, UNLOCK);
	safe_mutex(&philo->second_fork->fork, UNLOCK);
	safe_mutex(&philo->eat_die_mutex, UNLOCK);
}

/*
	Summary
	the process for a philosopher to think during the dinner simulation.

	if there is an even number of philosophers in the simulation they don't
	need to wait while thinking as they can just take in turns eating and
	sleeping. first even philosophers eat then odd philosophers eat and so on,
	there is never any contention for the forks.
	if there is an odd number of philosophers however, they will need to spend
	some time thinking to avoid one philosopher eating twice while another
	starves due to the limited amount of forks.
	the function will not print the thinking status while this function is used
	to desync the philosophers at the start of the simulation.
*/
void	think(t_philo *philo)
{
	long	t_eat;
	long	t_sleep;
	long	t_think;

	if (philo->data->num_of_philos % 2 == 0)
		return ;
	write_status(THINKING, philo, DEBUG_MODE);
	t_eat = philo->data->time_to_eat;
	t_sleep = philo->data->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think, philo->data);
}

/*
	Summary
	this function handles the scenario when there is only a single philosopher.
	because they only have one fork they cannot eat so they just pick up the fork
	and then wait to die.
*/
static void	*lone_philo(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, \
			get_time(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->num_threads_running);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!simulation_finished(philo->data))
		usleep(200);
	return (NULL);
}

/*
	Summary
	this function simulates a single philosopher as they eat, sleep, and think.
	it loops until the simulation finishes or the philosopher is full.

	Inputs
	philosopher: a pointer to a t_philo struct for the philosopher that is
		being simulated.

	Outputs
	none
*/
static void	*dinner_simulation(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time, \
			get_time(MILLISECOND));
	increase_long(&philo->data->data_mutex, &philo->data->num_threads_running);
	desync_philos(philo);
	while (!simulation_finished(philo->data))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		think(philo);
	}
	return (NULL);
}

/*
	Summary
	starts the dinner simulation. threads are created for each philosopher,
	and a monitor thread (ends the simulation if a philosopher dies). the
	function also sets the strat time at the beginning of the simulation, and
	updates the end_sim flag at the end of the simulation.

	Inputs
	data: a pointer to a t_data struct that contains the necessary data for
		the dinner simulation.

	Outputs
	none
*/
void	dinner_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->meals_limit == 0)
		return ;
	else if (data->num_of_philos == 1)
		safe_thread(&data->philos[0].thread_id, lone_philo, &data->philos[0], \
				CREATE);
	else
	{
		while (++i < data->num_of_philos)
			safe_thread(&data->philos[i].thread_id, dinner_simulation, \
			&data->philos[i], CREATE);
	}
	safe_thread(&data->monitor, monitor_dinner, data, CREATE);
	data->start_of_sim = get_time(MILLISECOND);
	set_bool(&data->data_mutex, &data->all_threads_ready, true);
	i = -1;
	while (++i < data->num_of_philos)
		safe_thread(&data->philos[i].thread_id, NULL, NULL, JOIN);
	safe_thread(&data->monitor, NULL, NULL, JOIN);
}
