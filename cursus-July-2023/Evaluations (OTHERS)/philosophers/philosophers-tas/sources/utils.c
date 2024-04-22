/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:37:02 by tday              #+#    #+#             */
/*   Updated: 2024/04/12 22:41:15 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	Summary
	prints an error message in red colour and exits the program

	Inputs
	error: a string containing the error message to be printed.
*/

/*
// OG TAS CODE
void	error_exit(const char *error)
{
	printf(RED"%s\n"DEF, error);
	exit(EXIT_FAILURE);
}
*/

void	error_exit(const char *error, t_msh *msh)
{
	printf(RED"%s\n"DEF, error);
	exit(msh->last_exit_status);
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
	data: a pointer to the t_data struct.
*/
void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < usec)
	{
		if (simulation_finished(data))
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
void	clean(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		philo = data->philos + i;
		safe_mutex(&philo->philo_mutex, DESTROY);
		safe_mutex(&philo->eat_die_mutex, DESTROY);
	}
	safe_mutex(&data->write_mutex, DESTROY);
	safe_mutex(&data->data_mutex, DESTROY);
	free(data->forks);
	free(data->philos);
}
