/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:23:01 by sentry            #+#    #+#             */
/*   Updated: 2024/05/05 22:27:54 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    Refine control over thinking
    1) Print the status and then check.
    If the philo nbr is even, i don't care return.
    Else
    Force to think philo 42% of the time and the % remaining is handled by 
    contention.
    Unconventional solution, 42 is a "Magic number" but in test cases it works.
    The thing is that I want to avoid a philo immediately eating after sleeping 
    without waiting a little for neighbour philo. 
    I tried many cases, but not sure if 100% robust.   
*/

void	thinking(t_philo *philo)
//static void thinking (t_philo *philo, bool pre_simulation)
{
	long	eating_time;
	long	sleeping_time;
	long	thinking_time;

	if (philo->data->philo_count % 2 == 0)
		return ;
	write_status(THINKING, philo, DEBUG_MODE);
	eating_time = philo->data->time_to_eat;
	sleeping_time = philo->data->time_to_sleep;
	thinking_time = eating_time * 2 - sleeping_time;
	if (thinking_time < 0)
		thinking_time = 0;
	precise_usleep(thinking_time * 0.30, philo->data);
}

/*
    LONE PHILO
    Same algo preliminary code as all the threads but...
    1) Fake to lock the first_fork with write_status just for output 
    purposes
    2) Sleep until the monitor will bust it (monitor wil eventually spot 
    the philo death, turning on end_sim)
*/

void	*lone_philo(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILLISECOND));
	increase_long(&philo->data->access_mutex,
		&philo->data->threads_running_count);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	while (!sim_finished(philo->data))
		usleep(200);
	return (NULL);
}

/*
    EAT ROUTINE
    1) Grab forks : here first and second fork are handy 
	(don't worry about R and L)
    2) Eat: write eat, update last meal, update meal_count
        eventually bool full
    3) Release forks

    last_meal_time happens before eating : this is helpful to avoid deaths while 
    a philo is eating
*/

static void	eating(t_philo *philo)
{
	safe_mutex(&philo->first_fork->fork_mutex, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->second_fork->fork_mutex, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	safe_mutex(&philo->eat_die_mutex, LOCK);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILLISECOND));
	philo->meal_count++;
	write_status(EATING, philo, DEBUG_MODE);
	safe_mutex(&philo->eat_die_mutex, UNLOCK);
	precise_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->meal_limit > 0
		&& philo->meal_count == philo->data->meal_limit)
		set_bool(&philo->philo_mutex, &philo->full, true);
	safe_mutex(&philo->first_fork->fork_mutex, UNLOCK);
	safe_mutex(&philo->second_fork->fork_mutex, UNLOCK);
}

/*
    DINNER SIMULATION i.e. ACTUALY DINNER
    1) Wait all philos, synchronise start i.e. wait for all threads to be ready
    2) Increase the number of running threads, useful for monitor
    3) desynchronize_philos-> useful for fairness
    4) Start an endless loop, until a philo eventually dies or becomes full. 
        write_status will always check for end_simulation 
        flag before writing
*/

static void	*dinner_simulation(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	wait_all_threads(philo->data);
	set_long(&philo->philo_mutex, &philo->last_meal_time,
		get_time(MILLISECOND));
	increase_long(&philo->data->access_mutex,
		&philo->data->threads_running_count);
	synchronize_philos(philo);
	while (!sim_finished(philo->data))
	{
		if (philo->full)
			break ;
		eating(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo->data->time_to_sleep, philo->data);
		thinking(philo);
	}
	return (NULL);
}

/*
	./philo 	5	800 	200 	200 	[5]
	1) If no meals, return to main and clean
	2) If only 1 philo ->ad hoc function
	3) Create all threads, all philos
    4) Create a monitor thread -> dead
    5) Synchronize the beginning of the sim
        pthread_create->philo starts running!
        every philo start simultaneously
    6) JOIN everyone

    1) Create all the philosophers
    2) Create another one thread searching for death ones
    3) Set time_start_simulation and set true ready all, so they can 
    start simulation
    4) Wait for all
    5) If we pass line 188 it means all philos are full so set 
    end_sim for monitor
    6) Wait for monitor as well. Then jump to clean in main
    
    If we join all threads it means they are all full, so the simulation 
    is finished, therefore we set the end_simulation ON
 
    Useful cause also monitor uses this boolean, can be turned on by philos 
    ending cause full or by monitor cause a philo died
    -> It's a "2 way" bool for threads communication
*/

void	start_dinner(t_data	*data)
{
	int	i;

	i = -1;
	if (data->meal_limit == 0)
		return ;
	else if (data->philo_count == 1)
		safe_thread(&data->philos_arr[0].thread_id, lone_philo,
			&data->philos_arr[0], CREATE);
	else
	{
		while (++i < data->philo_count)
			safe_thread(&data->philos_arr[i].thread_id, dinner_simulation,
				&data->philos_arr[i], CREATE);
	}
	safe_thread(&data->monitor, monitor_dinner, data, CREATE);
	data->sim_start_time = get_time(MILLISECOND);
	set_bool(&data->access_mutex, &data->all_threads_ready, true);
	i = -1;
	while (++i < data->philo_count)
		safe_thread(&data->philos_arr[i++].thread_id, NULL, NULL, JOIN);
	safe_thread(&data->monitor, NULL, NULL, JOIN);
}
