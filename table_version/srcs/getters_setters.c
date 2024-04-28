/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:35:10 by sentry            #+#    #+#             */
/*   Updated: 2024/04/28 15:49:02 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
    Contains getters and setters to avoid writing LOCK UNLOCK everywhere.
    Have only used longs and bools as you only need to use 2 types of setters 
    and getters (value type safety and performance). Would be better to use
    another approach if you value flexibity and scalability.
*/

// BOOL - set to value thread safe

void set_bool(t_mtx *mutex, bool *dest, bool value)
{
    safe_mutex_handle(mutex, LOCK);
    *dest = value;
    safe_mutex_handle(mutex, UNLOCK);
}

/*
// OG
bool get_bool(t_mtx *mutex, bool *value)
{
    bool    ret;

	//
    if (!mutex || !value)
    {
        fprintf(stderr, "get_bool called with NULL mutex or value pointer\n");
        abort();
    }
	//
    safe_mutex_handle(mutex, LOCK);
    ret = *value;
    safe_mutex_handle(mutex, UNLOCK);
    return (ret);
}
*/

bool get_bool(t_mtx *mutex, bool *value)
{
    bool    ret;

    if (!mutex || !value)
    {
        fprintf(stderr, "get_bool called with NULL mutex or value pointer\n");
        abort();
    }

    printf("Attempting to lock mutex %p to get bool value %p\n", mutex, value);
    safe_mutex_handle(mutex, LOCK);
    ret = *value;
    printf("Obtained bool value %d from address %p\n", ret, value);
    safe_mutex_handle(mutex, UNLOCK);
    printf("Unlocked mutex %p\n", mutex);
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
bool    sim_finished(t_table *table)
{
    return (get_bool(&table->table_mutex, &table->end_sim));
}
