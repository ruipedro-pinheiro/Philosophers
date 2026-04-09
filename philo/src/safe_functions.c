/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:02:52 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/03 16:08:05 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
** @brief Handle pthread_create/pthread_join error codes
** @param status Return value from the pthread function
** @param opcode The operation that was attempted (CREATE or JOIN)
** @note Does nothing if status is 0 (success)
** @see thread_handler() which calls this after each pthread operation
*/
void	thread_error_handler(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		exit_error("Not enough resources to create another thread");
	else if (EPERM == status)
		exit_error("Missing permissions to create new thread");
	else if (EINVAL == status && (CREATE == opcode))
		exit_error("Specified value is invalid");
	else if (ESRCH == status)
		exit_error("No thread was found with specified ID");
	else if (EDEADLK == status)
		exit_error("Deadlock was found");
}

/*
** @brief Wrapper for pthread_create and pthread_join with error handling
** @param thread Pointer to the pthread_t variable
** @param foo Thread start routine (NULL for JOIN)
** @param data Argument passed to the thread routine (NULL for JOIN)
** @param opcode CREATE or JOIN
** @warning Only CREATE and JOIN are supported — other opcodes print an error
** @see thread_error_handler() for error code interpretation
*/
void	thread_handler(pthread_t *thread, void *(*foo)(void *), void *data,
		t_opcode opcode)
{
	if (CREATE == opcode)
		thread_error_handler(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		thread_error_handler(pthread_join(*thread, NULL), opcode);
	else
	{
		exit_error("Invalid OPCODE for thread handler:");
		exit_error("Please use <CREATE> <JOIN>");
	}
}

/*
** @brief Handle pthread_mutex error codes for all mutex operations
** @param status Return value from the pthread_mutex function
** @param opcode The operation attempted (LOCK, UNLOCK, INIT, or DESTROY)
** @note Does nothing if status is 0 (success)
** @see mutex_handler() which calls this after each mutex operation
*/
void	mutex_error_handler(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode
			|| DESTROY == opcode))
		exit_error("Value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		exit_error("Value specified by mutex is invalid");
	else if (EDEADLK == status)
		exit_error("A Deadlock would occur if the thread blocked mutex");
	else if (EPERM == status)
		exit_error("Thread has no permission over mutex lock");
	else if (ENOMEM == status)
		exit_error("Not enough memory to create another mutex");
	else if (EBUSY == status)
		exit_error("Mutex is currently locked");
}

/*
** @brief Wrapper for all pthread_mutex operations with error handling
** @param mutex Pointer to the mutex to operate on
** @param opcode LOCK, UNLOCK, INIT, or DESTROY
** @warning Prints error and continues on failure — does not exit
** @see mutex_error_handler() for error code interpretation
** @see data_init() and cleanup() for INIT/DESTROY usage
*/
void	mutex_handler(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		mutex_error_handler(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		mutex_error_handler(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		mutex_error_handler(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		mutex_error_handler(pthread_mutex_destroy(mutex), opcode);
	else
		exit_error("Wrong opcode");
}
