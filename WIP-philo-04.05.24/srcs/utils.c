/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:46:22 by atang             #+#    #+#             */
/*   Updated: 2024/05/05 09:03:23 by sentry           ###   ########.fr       */
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

long	get_time(t_time_code time_code)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		error_exit("Gettimeofday failed");
	if (time_code == SECOND)
		return (current_time.tv_sec + current_time.tv_usec / 1e6);
	else if (time_code == MILLISECOND)
		return ((current_time.tv_usec * 1e3) + (current_time.tv_usec / 1e3));
	else if (time_code == MICROSECOND)
		return ((current_time.tv_usec * 1e6) + current_time.tv_usec);
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

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (sim_finished(data))
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
void	clean(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	//i = 0; in thuy's
	while (i < data->philo_count)
	{
		philo = data->philos_arr + i;
		safe_mutex(&philo->philo_mutex, DESTROY);
		i++;
	}
	safe_mutex(&data->write_mutex, DESTROY);
	safe_mutex(&data->access_mutex, DESTROY);
	free(data->forks_arr);
	free(data->philos_arr);
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
	printf(C"%s\n"RST, msg);
}
