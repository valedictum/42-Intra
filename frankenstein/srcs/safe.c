/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 20:56:39 by tday              #+#    #+#             */
/*   Updated: 2024/04/28 17:56:03 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Summary
a wrapper around the malloc function. allocates memory and returns a pointer
to the allocated memory. If the malloc function fails, the safe_malloc function
calls the error_exit function to handle the error.

Inputs
bytes: The number of bytes to allocate.

Outputs
result: a pointer to the allocated memory.
*/
void	*safe_malloc(size_t bytes)
{
	void	*result;

	result = malloc(bytes);
	if (result == NULL)
		error_exit("error with malloc");
	return (result);
}

/*
Summary
handles errors related to mutex operations.

Inputs
status: An integer representing the return value of a mutex operation.
opcode: An enumeration value indicating the type of mutex operation.

Outputs
none. it handles errors by calling the error_exit function with the
corresponding error message.
*/
static void	mutex_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK || \
	opcode == DESTROY))
		error_exit("the value specified by mutex is invalid");
	else if (status == EINVAL && opcode == INIT)
		error_exit("the value specified by attr is invalid");
	else if (status == EDEADLK)
		error_exit("a deadlock would occur if the thread blocked waiting for \
		mutex");
	else if (status == EPERM)
		error_exit("the current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		error_exit("the process cannot allocate enough memory to create \
		another mutex");
	else if (status == EBUSY)
		error_exit("mutex is locked");
}

/*
Summary
a wrapper around the pthread_mutex functions in c. it calls a mutex operation
based on the opcode. it also handles any errors that may occur during the mutex
operation with the mutex_error function.

Inputs
mutex: a pointer to a mutex object.
opcode: an enumeration value indicating the type of mutex operation to perform.

Outputs
none. the function performs the specified mutex operation and handles any errors
that may occur.
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
		error_exit("wrong opcode for mutex");
}

/*
Summary
handles errors related to thread operations.

Inputs
status: an integer representing the return value of a thread operation.
opcode: an enumeration value indicating the type of thread operation.

Outputs
none. it handles errors by calling the error_exit function with the
corresponding error message.
*/
static void	thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	else if (status == EAGAIN)
		error_exit("no resourses to create another thread");
	else if (status == EPERM)
		error_exit("the caller does not have appropriate permission");
	else if (status == EINVAL && opcode == CREATE)
		error_exit("the value specified by attr is invalid");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_exit("the value specified by thread is not joinable");
	else if (status == ESRCH)
		error_exit("no thread could be found corresponding to that specified \
		by the given thread id");
	else if (status == EDEADLK)
		error_exit("a deadlock was detected or the value of thread specifies \
		the calling thread");
}

/*
Summary
a wrapper around the pthread library functions in c. it calls a thread operation
based on the opcode. it also handles any errors that may occur during the thread
operation with the thread_error function.

Inputs
thread: a pointer to a pthread_t object representing the thread.
foo: a function pointer to a function that takes a void* argument and returns a
void*. this function will be executed by the thread.
data: a void* pointer to the data that will be passed to the thread function.
opcode: an enumeration value (CREATE, JOIN, or DETACH) indicating the type of
thread operation to perform.

none. the function performs the specified thread operation and handles any errors
that may occur.
*/
void	safe_thread(pthread_t *thread, void *(*foo)(void *), void *data, \
		t_opcode opcode)
{
	if (opcode == CREATE)
		thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		thread_error(pthread_detach(*thread), opcode);
	else
		error_exit("wrong opcode for thread");
}
