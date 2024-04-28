/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:23:01 by sentry            #+#    #+#             */
/*   Updated: 2024/04/28 15:48:57 by atang            ###   ########.fr       */
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
void thinking (t_philo *philo, bool pre_simulation)
{
    long    t_eat;
    long    t_sleep;
    long    t_think;

    if (!pre_simulation)
        write_status(THINKING, philo, DEBUG_MODE);
    if (philo->table->philos_num % 2 == 0)
        return ;
    t_eat = philo->table->time_to_eat;
    t_sleep = philo->table->time_to_sleep;
    t_think = (t_eat * 2) - t_sleep;
    if (t_think < 0)
        t_think = 0;
    // precise control I wanna make on philo
    precise_usleep(t_think * 0.42, philo->table);
}

/*
    LONE PHILO
    Same algo preliminary code as all the threads but...
    1) Fake to lock the first_fork with write_status just for output 
    purposes
    2) Sleep until the monitor will bust it (monitor wil eventually spot 
    the philo death, turning on end_sim)
*/

void    *lone_philo(void    *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    wait_all_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
    increase_long(&philo->table->table_mutex, &philo->table->threads_running_num);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    while (!sim_finished(philo->table))
        precise_usleep(200, philo->table);
    return (NULL);
}

/*
    EAT ROUTINE
    1) Grab forks : here first and second fork are handy (don't worry about R and L)
    2) Eat: write eat, update last meal, update meal_count
        eventually bool full
    3) Release forks

    last_meal_time happens before eating : this is helpful to avoid deaths while 
    a philo is eating
*/

static void    eat(t_philo *philo)
{
    safe_mutex_handle(&philo->first_fork->fork, LOCK);
    write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
    safe_mutex_handle(&philo->second_fork->fork, LOCK);
    write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
    set_long(&philo->philo_mutex, &philo->last_meal_time, get_time(MILLISECOND));
    philo->meal_count++;
    write_status(EATING, philo, DEBUG_MODE);
    precise_usleep(philo->table->time_to_eat, philo->table);
    if (philo->table->num_limit_meals > 0 
        && philo->meal_count == philo->table->num_limit_meals)
        set_bool(&philo->philo_mutex, &philo->full, true);
    safe_mutex_handle(&philo->first_fork->fork, UNLOCK);
    safe_mutex_handle(&philo->second_fork->fork, UNLOCK);
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

static void    *dinner_simulation(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    wait_all_threads(philo->table);
    set_long(&philo->philo_mutex, &philo->last_meal_time,
            get_time(MILLISECOND));
    increase_long(&philo->table->table_mutex, 
            &philo->table->threads_running_num);
    desynchronize_philos(philo);
    while(!sim_finished(philo->table))
    {
        if (get_bool(&philo->philo_mutex, &philo->full))
            break ;
        eat(philo);
        write_status(SLEEPING, philo, DEBUG_MODE);
        precise_usleep(philo->table->time_to_sleep, philo->table);
        thinking(philo, false);
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

/*
// OG
void    start_dinner(t_table *table)
{
    int     i;

    i = -1;
    if (table->num_limit_meals == 0)
        return ;
    else if (table->philos_num == 1)
        safe_thread_handle(&table->philos[0].thread_id, lone_philo, &table->philos[0], CREATE);
    else
    {
        while (i++ < table->philos_num)
            safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
                &table->philos[i], CREATE);
    }
	debug("Created thread");
    safe_thread_handle(&table->monitor, monitor_dinner, table, CREATE);
    table->start_sim = get_time(MILLISECOND);
    set_bool(&table->table_mutex, &table->all_threads_ready, true);
    i = -1;
    while (i++ < table->philos_num)
        safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
    set_bool(&table->table_mutex, &table->end_sim, true);
    safe_thread_handle(&table->monitor, NULL, NULL, JOIN);
}
*/

void    start_dinner(t_table *table)
{
    int     i;

    i = -1;
    if (table->num_limit_meals == 0)
        return ;
    else if (table->philos_num == 1)
        safe_thread_handle(&table->philos[0].thread_id, lone_philo, &table->philos[0], CREATE);
    else
    {
        while (i++ < table->philos_num)
            safe_thread_handle(&table->philos[i].thread_id, dinner_simulation,
                &table->philos[i], CREATE);
    }
	debug("Created thread");
    safe_thread_handle(&table->monitor, monitor_dinner, table, CREATE);
    table->start_sim = get_time(MILLISECOND);
    safe_mutex_handle(&table->all_threads_ready_mutex, LOCK);
    table->all_threads_ready = true;
    safe_mutex_handle(&table->all_threads_ready_mutex, UNLOCK);
    set_bool(&table->table_mutex, &table->all_threads_ready, true);
    i = -1;
    while (i++ < table->philos_num)
        safe_thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
    set_bool(&table->table_mutex, &table->end_sim, true);
    safe_thread_handle(&table->monitor, NULL, NULL, JOIN);
}