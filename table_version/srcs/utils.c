/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:46:22 by atang             #+#    #+#             */
/*   Updated: 2024/04/28 15:10:51 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	gettimeofday (monitor function)
	time_code -> SECONDS MILLISECONDS MICROSECONDS
	Returns time in milliseconds, microseconds, hence scientific notation is
	used.
	Return is used to trick -Werror as error_exit will already exit
*/

long	get_time(int time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("Gettimeofday failed");
	if (time_code == SECOND)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else if (time_code == MILLISECOND)
		return (tv.tv_sec * 1e3 + tv.tv_usec / 1e3);
	else if (time_code == MICROSECOND)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else
		error_exit("Wrong input to gettime:"
			"use <MILLISECOND> <MICROSECOND> <SECONDS>");
	return (1337);
}

/*
	HYBRID APPROACH
	Precise usleep - the real one sucks
	Why data? Is the simulation finished?
	1) usleep the majority of the time, not CPU intensive
	2) refine last microsecond with spinlock/busy wait
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
		if (remaining > 1e4)
			usleep(remaining / 2);
		else
		{
			while (get_time(MICROSECOND) - start < usec)
				;
		}
	}
}

// To clean to avoid memory leaks
void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->philos_num)
	{
		philo = table->philos + i;
		safe_mutex_handle(&philo->philo_mutex, DESTROY);
	}
	safe_mutex_handle(&table->write_mutex, DESTROY);
	safe_mutex_handle(&table->table_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
}
/*
	Print a custom error message and exit
 	R->RED
	RST->RESET
*/

void	error_exit(const char	*error_msg)
{
	printf(RED"%s\n"RST, error_msg);
	exit(EXIT_FAILURE);
}

void	debug(const char *msg)
{
	printf(Y"%s\n"RST, msg);
}