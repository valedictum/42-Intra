/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters_getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:35:10 by sentry            #+#    #+#             */
/*   Updated: 2024/04/26 23:21:12 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    Contains getters and setters to avoid writing LOCK UNLOCK everywhere.
    Have only used longs and bools as you only need to use 2 types of setters 
    and getters
*/

// BOOL

void set_bool(t_mtx *mutex, bool *dest, bool value)
{
    safe_mutex_handle(mutex, LOCK);
    *dest = value;
    safe_mutex_handle(mutex, UNLOCK);
}

bool get_bool(t_mtx *mutex, bool *value)
{
    bool    ret;

    safe_mutex_handle(mutex, LOCK);
    // READING thread safe
    ret = *value;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);
}

// LONG


long    get_long(t_mtx *mutex, long *value)
{
	long	ret;

	safe_mutex_handle(mutex, LOCK);
	ret = *value;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}

void set_long(t_mtx *mutex, long *dest, long value)
{
    safe_mutex_handle(mutex, LOCK);
    *dest = value;
    safe_mutex_handle(mutex, UNLOCK);
}

// Redundant? Not sure.
bool    sim_finished(t_data *data)
{
    return (get_bool(&data->table_mutex, &data->end_sim));
}
