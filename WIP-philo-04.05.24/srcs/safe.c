/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:47:44 by atang             #+#    #+#             */
/*   Updated: 2024/05/11 23:13:48 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Contains thread and mutex functions with embedded chekcs for errors
	on return. 2 clean wrappers (safe_mutex and safe_thread) 
	are used with OPCODE (enum) for safer, cleaner, more readbale code.
*/

//	MALLOC
void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (NULL == ret)
		error_exit("Error with malloc");
	return (ret);
}

/*
	HANDLING ERRORS
	If successful, all the mutex and thread fns with return (0),
	otherwise, they return an error number indicating the reason.

	Basicallly recreating perror but:
	1)	These fns () don't set errno
	2)	We can't use perror 
*/

static void	mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_exit("The value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EDEADLK == status)
		error_exit("A deadlock would occur if the thread "
			"blocked waiting for mutex.");
	else if (EPERM == status)
		error_exit("The current thread does not hold a lock on mutex.");
	else if (ENOMEM == status)
		error_exit("The process cannot allocate enough memory"
			" to create another mutex.");
	else if (EBUSY == status)
		error_exit("Mutex is locked");
}

/*
	THREADS - thread errors 
*/

static void	thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have apporpriate permission\n");
	else if (EINVAL == status && CREATE == opcode)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		error_exit("The value specified by thread is not joinable");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
			"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
			"thread specifies the calling thread");
}

/*
	ONE FN () TO HANDLE SAFELY
	SAFE MUTEX
	init
	destroy
	lock
	unlock
*/

void	safe_mutex(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("Wrong opcode for mutex handle"
			"use <LOCK> <UNLOCK> <INIT> <DESTROY>");
}

/*
	One funCtion to handle threads
	create join detach
*/

void	safe_thread(pthread_t *thread, void *(*foo)(void *),
	void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("Wrong opcode for thread handle:"
			" Use <CREATE> <JOIN> <DETACH>");
}