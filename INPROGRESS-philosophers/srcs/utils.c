/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:46:22 by atang             #+#    #+#             */
/*   Updated: 2024/04/26 22:39:46 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	gettimeofday (monitor function)
	time_code -> SECONDS MILLISECONDS MICROSECONDS
*/

long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_and_exit("Gettimeofday failed");
	if (time_code == SECOND)
		return (tv.tv_sec + (tv.tv_usec / 1e6));
	else if (time_code == MILLISECOND)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	else if (time_code == MICROSECOND)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_and_exit("Wrong input to get_time!");
	return (1337);
}

/*
	Precise usleep, the real one sucks
	Why data? Is the simulation finished?
	1) usleep the mjority of the time, not CPU intensive
	2) refine last microsecond with spinlock
*/

void	precise_usleep(long usec, t_data *data)
{
	long	start;
	long	elapsed;
	long	remaining;
	//long	total;

	start = get_time(MICROSECOND);
	while ((get_time(MICROSECOND) - start) < usec)
	{
		// 1)
		if (sim_finished(data))
			break ;
		elapsed = get_time(MICROSECOND) - start;
		remaining = usec - elapsed;

		// to get a spinlock threshold
		if (remaining > 1e3)
			usleep(remaining / 2); // usec / 2 originally?
		else
		{
			// SPINLOCK
			while ((get_time(MICROSECOND) - start) < usec)
				;
		}
	}
}

void	error_and_exit(const char	*error_msg)
{
	printf(RED"%s\n"RST, error_msg);
	exit(EXIT_FAILURE);
}
