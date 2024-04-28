/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:36:33 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 18:42:28 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Summary
	sets the value of a bool in a thread-safe manner.
	the use of a mutex ensures that the opperation of setting the boolean
	variable is atomic meaning it is uninteruptable and only one thread can
	update the value at a time. this avoids data corruption or a race condition
	where multiple threads try to alter the variable at the same time.

	Inputs
	mutex: a pointer to a mutex which blocks other threads from accessing the
		boolean until it has been unlocked at the end of the function.
	dest: a poointer to the boolean whos value will be set.
	value: the value to be assigned to the bool.

	Outputs
	none.
*/
void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

/*
	Summary
	retrieves the value of a boolean variable in a thread-safe manner by using
	a mutex to ensure atomicity. this stops any other thread from updating the
	value if the bool variable while this function is reading it.

	Inputs
	mutex: a pointer to a mutex that blocks other threads from accessing the
		variable until it is unlocked.
	value: a pointer to the boolean variable whose value will be retrieved.

	Outputs
	result: the value of the boolean variable 'value'.
*/
bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	result;

	safe_mutex(mutex, LOCK);
	result = *value;
	safe_mutex(mutex, UNLOCK);
	return (result);
}

/*
	Summary
	sets the value of a long integer in a thread-safe manner.
	the use of a mutex ensures that the opperation of setting the long
	variable is atomic meaning it is uninteruptable and only one thread can
	update the value at a time. this avoids data corruption or a race condition
	where multiple threads try to alter the variable at the same time.

	Inputs
	mutex: a pointer to a mutex which blocks other threads from accessing the
		variable until it has been unlocked at the end of the function.
	dest: a poointer to the long variable whos value will be set.
	value: the value to be assigned to the long variable.

	Outputs
	none.
*/
void	set_long(t_mtx *mutex, long *dest, long value)
{
	safe_mutex(mutex, LOCK);
	*dest = value;
	safe_mutex(mutex, UNLOCK);
}

/*
	Summary
	retrieves the value of a long variable in a thread-safe manner by using
	a mutex to ensure atomicity. this stops any other thread from updating the
	value if the long variable while this function is reading it.

	Inputs
	mutex: a pointer to a mutex that blocks other threads from accessing the
		variable until it is unlocked.
	value: a pointer to the long variable whose value will be retrieved.

	Outputs
	result: the value of the long variable 'value'.
*/
long	get_long(t_mtx *mutex, long *value)
{
	long	result;

	safe_mutex(mutex, LOCK);
	result = *value;
	safe_mutex(mutex, UNLOCK);
	return (result);
}

/*
	Summary
	checks if the simulation has finished by retrieving the value of the
	'end_sim' bool in a thread-safe manner by using the 'get_bool' function.

	Inputs
	data: a pointer to a t_data struct that contains the 'end_sim' bool.

	Outputs
	the value of the 'end_sim' bool, indicating whether the simulation has
	finished or not.
*/
bool	sim_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_sim));
}
