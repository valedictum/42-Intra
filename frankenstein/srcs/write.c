/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:06:31 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 18:35:18 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Summary
	called by the 'write_status' function to print a debug status based on the
	opcode.
	separated due to function line limit
*/
static void	debug_status(t_philo_status status, t_philo *philo, long elapsed)
{
	if (status == TAKE_FIRST_FORK && !sim_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken 1st fork\t"Y \
		"fork id\t\t[%d]\n"RST, elapsed, philo->philo_id, \
		philo->first_fork->fork_id);
	else if (status == TAKE_SECOND_FORK && !sim_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken 2nd fork\t"Y \
		"fork id\t\t[%d]\n"RST, elapsed, philo->philo_id, \
		philo->second_fork->fork_id);
	else if (status == EATING && !sim_finished(philo->table))
		printf(W"%-6ld"RST" %d is eating\t\t"M \
		"meal count\t[%ld]\n"RST, elapsed, philo->philo_id, philo->meal_count);
	else if (status == SLEEPING && !sim_finished(philo->table))
		printf(W"%-6ld"RST" %d is sleeping\n"RST, elapsed, philo->philo_id);
	else if (status == THINKING && !sim_finished(philo->table))
		printf(W"%-6ld"RST" %d is thinking\n"RST, elapsed, philo->philo_id);
	else if (status == DIED)
		printf(W"%-6ld"RST" %d died\n"RST, elapsed, philo->philo_id);
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
		&& !sim_finished(philo->table))
		printf(W"%-6ld"RST" %d has taken a fork\n", elapsed, philo->philo_id);
	else if (status == EATING && !sim_finished(philo->table))
		printf(W"%-6ld"C" %d is eating\n"RST, elapsed, philo->philo_id);
	else if (status == SLEEPING && !sim_finished(philo->table))
		printf(W"%-6ld"B" %d is sleeping\n"RST, elapsed, philo->philo_id);
	else if (status == THINKING && !sim_finished(philo->table))
		printf(W"%-6ld"Y" %d is thinking\n"RST, elapsed, philo->philo_id);
	else if (status == DIED)
		printf(W"%-6ld"RST" %d died\n"RST, elapsed, philo->philo_id);
	else if (status == FULL)
		printf(W"%-6ld"G" all philosophers have eaten [%ld] times\n" \
		RST, elapsed, philo->meal_count);
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

	elapsed = get_time(MILLISECOND) - philo->table->start_sim;
	if (philo->full && !philo->table->all_philos_full)
		return ;
	safe_mutex(&philo->table->write_mutex, LOCK);
	if (debug)
		debug_status(status, philo, elapsed);
	else
		regular_status(status, philo, elapsed);
	safe_mutex(&philo->table->write_mutex, UNLOCK);
}
