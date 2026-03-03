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

void	thread_error_handler(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		exit_error("Not enough ressources to create another thread");
	else if (EPERM == status)
		exit_error("Missing permissions to create new thread");
	else if (EINVAL == status && (CREATE == opcode))
		exit_error("Specified value is invalid");
	else if (EINVAL == status && (CREATE == opcode || DETACH == opcode))
		exit_error("Value specified by thread is not joinable");
	else if (ESRCH == status)
		exit_error("No thread was found with specified ID");
	else if (EDEADLK == status)
		exit_error("Deadlock was found");
}

void	thread_handler(pthread_t *thread, void *(*foo)(void *), void *data,
		t_opcode opcode)
{
	if (CREATE == opcode)
		thread_error_handler(pthread_create(thread, NULL, foo, data), opcode);
	else if (JOIN == opcode)
		thread_error_handler(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		thread_error_handler(pthread_detach(*thread), opcode);
	else
	{
		exit_error("Invalid OPCODE for thread handler:");
		exit_error("Please use <CREATE> <JOIN> <DETACH>");
	}
}

void	mutex_error_handler(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode
			|| DESTROY == opcode))
		exit_error("Value specified by mutex is invalid");
	else if (EINVAL == status && INIT == opcode)
		exit_error("Value specified bt mutex is invalid");
	else if (EDEADLK == status)
		exit_error("A Deadlock would occcur if the thread blocked mutex");
	else if (EPERM == status)
		exit_error("Tread has no permission over mutex lock");
	else if (ENOMEM == status)
		exit_error("Not enough memory to create another mutex");
	else if (EBUSY == status)
		exit_error("Mutex is currently locked");
}

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
