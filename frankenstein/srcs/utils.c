/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:37:02 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 19:00:40 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Summary
	prints an error message in red colour and exits the program

	Inputs
	error: a string containing the error message to be printed.
*/

void	error_exit(const char *error)
{
	printf(R"%s\n"RST, error);
	exit(EXIT_FAILURE);
}

/*
	Summary
	retrieves the current time in different units using the gettimeofday
	function.

	Inputs
	time_code: and enum value ('SECOND', 'MILLISECOND', or 'MICROSECOND')
		representing the desired time unit.

	Outputs
	the current time of day in the specified unit.
*/
long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("gettimeofday failed");
	if (time_code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time_code == MILLISECOND)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time_code == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("wrong input to get_time");
	return (42);
}

/*
	Summary
	pauses the execution of a function for a specified amount of time,
	similarly to usleep. usleep however is not very precise, it will pause
	a function for at least the given amount of time but it's not fussed if it
	goes a little over that time. to fix this the precise_usleep function will
	usleep for the majority of the time and then spinlock for the final
	milliseconds.

	Inputs
	usec: the duration of the pause in microseconds.
	table: a pointer to the t_table struct.
*/
void	precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (sim_finished(table))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		remaining = usec - elapsed;
		if (remaining > 1e3)
			usleep(remaining / 2);
		else
			while (get_time(MICROSECOND) - start < usec)
				;
	}
}

/*
	Summary
	cleans up the resources used by the program. it destroys mutexes and frees
	memory allocated for the forks and philosophers.
*/
void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->philos_num)
	{
		philo = table->philos + i;
		safe_mutex(&philo->philo_mutex, DESTROY);
		safe_mutex(&philo->eat_die_mutex, DESTROY);
	}
	safe_mutex(&table->write_mutex, DESTROY);
	safe_mutex(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}

void	debug(const char *msg)
{
	printf(Y"%s\n"RST, msg);
}
