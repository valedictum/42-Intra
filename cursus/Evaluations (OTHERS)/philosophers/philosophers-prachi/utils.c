/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:58:36 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 20:02:29 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alive_check(t_data_philo *philo)
{
	pthread_mutex_lock(philo->main_lock);
	if (!philo->stop)
	{
		pthread_mutex_unlock(philo -> main_lock);
		return (1);
	}
	pthread_mutex_unlock(philo -> main_lock);
	return (0);
}

void	print_info(t_data_philo *philo, char *action)
{
	long int	time;

	pthread_mutex_lock(philo -> write_message);
	time = get_time_now() - *philo -> start_time;
	if (time >= 0 && time <= 2147483647 && alive_check(philo))
		printf("[%d] Philo: %d %s\n", (int)time, philo -> philo_id, action);
	pthread_mutex_unlock(philo -> write_message);
}

int	digit_check(char *c)
{
	while (c && *c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

int	is_int(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (result > 2147483647)
			return (-1);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (1);
}

int	atoi_philo(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}
