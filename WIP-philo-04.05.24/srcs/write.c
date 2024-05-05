/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 21:47:08 by sentry            #+#    #+#             */
/*   Updated: 2024/05/05 14:13:19 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    same as write, just with more information to help when debugging
*/

static void	write_status_debug(t_philo_status status, t_philo *philo,
	long elapsed)
{
	if (TAKE_FIRST_FORK == status && !sim_finished(philo->data))
		printf(W"%-6ld"RST" %d has taken a FIRST fork\n"
			"\t\t\t"B"🍴 #%d\n"RST, elapsed, philo->philo_id,
			philo->first_fork->fork_id);
	else if (TAKE_SECOND_FORK == status && !sim_finished(philo->data))
		printf(W"%-6ld"RST" %d has taken a SECOND fork\n"
			"\t\t\t"B"🍴 #%d\n"RST, elapsed, philo->philo_id,
			philo->second_fork->fork_id);
	else if (EATING == status && !sim_finished(philo->data))
		printf(W"%-6ld"RST" %d is eating\n"
			"\t"Y"🍝 #%ld\n"RST, elapsed, philo->philo_id, philo->meal_count);
	else if (SLEEPING == status && !sim_finished(philo->data))
		printf(W"%6ld"RST" %d is sleeping\n", elapsed, philo->philo_id);
	else if (THINKING == status && !sim_finished(philo->data))
		printf(W"%6ld"RST" %d is thinking\n", elapsed, philo->philo_id);
	else if (DIED == status)
		printf(RED"%6ld %d died 💀\n"RST, elapsed, philo->philo_id);
}

/*
    fn () to write the philo status to standard output in a threadsafe manner

    [time_ms] [philo_id] [action]
    LOCK write
    LOCK philo's mutex to read meal_count
    LOCK table's lock to read if end_sim
*/

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = get_time(MILLISECOND) - philo->data->sim_start_time;
	if (get_bool(&philo->philo_mutex, &philo->full))
		return ;
	safe_mutex(&philo->data->write_mutex, LOCK);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !sim_finished(philo->data))
			printf(W"%-6ld"RST" %d has taken a fork\n", elapsed,
				philo->philo_id);
		else if (EATING == status && !sim_finished(philo->data))
			printf(W"%-6ld"RST" %d is eating\n", elapsed, philo->philo_id);
		else if (SLEEPING == status && !sim_finished(philo->data))
			printf(W"%-6ld"RST" %d is sleeping\n", elapsed, philo->philo_id);
		else if (THINKING == status && !sim_finished(philo->data))
			printf(W"%-6ld"RST" %d is thinking\n", elapsed, philo->philo_id);
		else if (DIED == status)
			printf(W"%-6ld"RST" %d died\n", elapsed, philo->philo_id);
	}
	safe_mutex(&philo->data->write_mutex, UNLOCK);
}
