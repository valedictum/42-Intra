/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:06:31 by tday              #+#    #+#             */
/*   Updated: 2023/12/23 20:35:29 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Summary
	called by the 'write_status' function to print a debug status based on the
	opcode.
	separated due to function line limit
*/
static void	debug_status(t_philo_status status, t_philo *philo, long elapsed)
{
	if (status == TAKE_FIRST_FORK && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"DEF" %d has taken 1st fork\t"YELLOW \
		"fork id\t\t[%d]\n"DEF, elapsed, philo->id, \
		philo->first_fork->fork_id);
	else if (status == TAKE_SECOND_FORK && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"DEF" %d has taken 2nd fork\t"YELLOW \
		"fork id\t\t[%d]\n"DEF, elapsed, philo->id, \
		philo->second_fork->fork_id);
	else if (status == EATING && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"MGNTA" %d is eating\t\t"MGNTA \
		"meal count\t[%ld]\n"DEF, elapsed, philo->id, philo->meals_count);
	else if (status == SLEEPING && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"BLUE" %d is sleeping\n"DEF, elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"YELLOW" %d is thinking\n"DEF, elapsed, philo->id);
	else if (status == DIED)
		printf(WHITE"%-6ld"RED" %d died\n"DEF, elapsed, philo->id);
}

/*
	Summary
	called by the 'write_status' function to print a regular status based on the
	opcode.
	separated due to function line limit
*/
static void	regular_status(t_philo_status status, t_philo *philo, long elapsed)
{
	if ((status == TAKE_FIRST_FORK || status == TAKE_SECOND_FORK) \
		&& !simulation_finished(philo->data))
		printf(WHITE"%-6ld"DEF" %d has taken a fork\n", elapsed, philo->id);
	else if (status == EATING && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"CYAN" %d is eating\n"DEF, elapsed, philo->id);
	else if (status == SLEEPING && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"BLUE" %d is sleeping\n"DEF, elapsed, philo->id);
	else if (status == THINKING && !simulation_finished(philo->data))
		printf(WHITE"%-6ld"YELLOW" %d is thinking\n"DEF, elapsed, philo->id);
	else if (status == DIED)
		printf(WHITE"%-6ld"RED" %d died\n"DEF, elapsed, philo->id);
	else if (status == FULL)
		printf(WHITE"%-6ld"GREEN" all philosophers have eaten [%ld] times\n" \
		DEF, elapsed, philo->meals_count);
}

/*
	Summary
	prints the status of a philosopher during the simulation.

	Inputs
	status: the status of the philosopher (e.g. EATING, SLEEPING, THINKING)
	philo: a pointer to the philosopher struct.
	debug: a flag indicating whether or not to print debug information.

	Outputs
	none. just prints status to standard output.
*/
void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->data->start_of_sim;
	if (philo->full && !philo->data->all_philos_full)
		return ;
	safe_mutex(&philo->data->write_mutex, LOCK);
	if (debug)
		debug_status(status, philo, elapsed);
	else
		regular_status(status, philo, elapsed);
	safe_mutex(&philo->data->write_mutex, UNLOCK);
}
