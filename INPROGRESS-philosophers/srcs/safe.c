/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:47:44 by atang             #+#    #+#             */
/*   Updated: 2024/04/25 18:26:49 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Contains wrapper functions with embedded controls on return
*/

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_and_exit("Error with malloc");
	return (ret);
}

/*
	Embed controls on return status
*/

static void	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode || DESTROY == opcode))
		error_and_exit("The value specified by mutex is invalid.");
	else if (EINVAL == status && INIT == opcode)
		error_and_exit("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		error_and_exit("A deadlock would occur if the thread blocked waiting for mutex.");
	else if (EPERM == status)
		error_and_exit("The current thread does not hold a lock on mutex");
	else if (ENOMEM == status)
		error_and_exit("The process cannot allocate enough memory to create another mutex.");
	else if (EBUSY == status)
		error_and_exit("Mutex is locked");
}

/*
	SAFE MUTEX
	init
	destroy
	lock
	unlock
*/

void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		handle_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		handle_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		handle_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_and_exit("Wrong opcode for mutex handle");
}
