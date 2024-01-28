/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:37:19 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 19:37:21 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time_now(void)
{
	struct timeval	time;
	long int		seconds_in_milliseconds;
	long int		nanoseconds_in_milliseconds;
	long int		total_milliseconds;

	gettimeofday(&time, NULL);
	seconds_in_milliseconds = time.tv_sec * 1000;
	nanoseconds_in_milliseconds = time.tv_usec / 1000;
	total_milliseconds = seconds_in_milliseconds + nanoseconds_in_milliseconds;
	return (total_milliseconds);
}

void	new_sleep(int mil_sec)
{
	long int	start_time;

	start_time = get_time_now();
	while ((get_time_now() - start_time) < mil_sec)
		usleep(100);
}

int	wait_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table -> philos_num)
	{
		pthread_join(table -> threads[i], NULL);
		i++;
	}
	return (0);
}
