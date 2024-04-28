/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:39:24 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 18:08:48 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	philo->meal_count++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo->table->time_to_eat, philo->table);
	if (philo->table->num_limit_meals > 0 && \
	philo->meal_count == philo->table->num_limit_meals)
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

	if (philo->table->philos_num % 2 == 0)
		return ;
	write_status(THINKING, philo, DEBUG_MODE);
	t_eat = philo->table->time_to_eat;
	t_sleep = philo->table->time_to_sleep;
	t_think = t_eat * 2 - t_sleep;
	if (t_think < 0)
		t_think = 0;
	precise_usleep(t_think, philo->table);
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
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, \
			get_time(MILLISECOND));
	increase_long(&philo->table->table_mutex, &philo->table->threads_running_num);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!sim_finished(philo->table))
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
	wait_all_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal_time, \
			get_time(MILLISECOND));
	increase_long(&philo->table->table_mutex, &philo->table->threads_running_num);
	desync_philos(philo);
	while (!sim_finished(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->table->time_to_sleep, philo->table);
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
	table: a pointer to a t_table struct that contains the necessary table for
		the dinner simulation.

	Outputs
	none
*/
void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table->num_limit_meals == 0)
		return ;
	else if (table->philos_num == 1)
		safe_thread(&table->philos[0].thread_id, lone_philo, &table->philos[0], \
				CREATE);
	else
	{
		while (++i < table->philos_num)
			safe_thread(&table->philos[i].thread_id, dinner_simulation, \
			&table->philos[i], CREATE);
	}
	safe_thread(&table->monitor, monitor_dinner, table, CREATE);
	table->start_sim = get_time(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->philos_num)
		safe_thread(&table->philos[i].thread_id, NULL, NULL, JOIN);
	safe_thread(&table->monitor, NULL, NULL, JOIN);
}
