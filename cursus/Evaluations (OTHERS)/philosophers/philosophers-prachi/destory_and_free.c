/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchawda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:34:58 by pchawda           #+#    #+#             */
/*   Updated: 2024/01/04 19:35:10 by pchawda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table -> philos_num)
	{
		pthread_mutex_destroy(&table -> forks[i]);
		pthread_mutex_destroy(&table -> priv_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&table -> main_lock);
	pthread_mutex_destroy(&table -> write_message);
}

void	free_all(t_table *table)
{
	if (table)
	{
		free(table -> threads);
		free(table -> forks);
		free(table -> philos);
		free(table -> priv_lock);
		free(table);
	}
}
