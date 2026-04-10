/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:07:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 11:53:53 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
** @brief Thread-safe print: locks table_mutex, checks death, prints message
** @param philo Pointer to the philosopher issuing the message
** @param msg The status message ("is eating", "has taken a fork", etc.)
** @note Timestamp is relative to time_start_sim, displayed in milliseconds
** @note If simulation is already finished, prints nothing and returns
** @warning Locks table_mutex — do not call while already holding table_mutex
** @see get_end_simulation() which also locks table_mutex for "died" message
*/
void	safe_print(t_philo *philo, char *msg)
{
	long	timestamp;

	mutex_handler(&philo->table->table_mutex, LOCK);
	timestamp = (get_time(MICROSECOND) - philo->table->time_start_sim) / 1000;
	if (simulation_finished(philo->table))
	{
		mutex_handler(&philo->table->table_mutex, UNLOCK);
		return ;
	}
	printf("%ld %ld %s\n", timestamp, philo->id, msg);
	mutex_handler(&philo->table->table_mutex, UNLOCK);
}

/*
** @brief Wrapper around malloc that prints an error on failure
** @param bytes Number of bytes to allocate
** @return void* Pointer to the allocated memory
** @warning Returns NULL on failure — caller should handle this
** @see data_init() where this is used for philos and forks allocation
*/
void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		exit_error("Malloc didn't work"); // NOT SAFE ! TODO
	return (ret);
}

/*
** @brief Print an error message to stdout and return 1
** @param msg The error message to display
** @return int Always returns 1
** @note Does not exit the program — caller must handle the return value
*/
int	exit_error(const char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

/*
** @brief Get current time in the requested unit using gettimeofday
** @param timecode SECOND, MILLISECOND, or MICROSECOND
** @return long Current time in the requested unit
** @note Internally all timestamps use MICROSECOND for precision
** @warning Calls exit_error if gettimeofday fails or invalid timecode
*/
long	get_time(t_timecode timecode)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		exit_error("Could not get time of day");
	if (SECOND == timecode)
		return (tv.tv_sec * 1e3 + (tv.tv_usec / 1e6));
	else if (MILLISECOND == timecode)
		return (tv.tv_sec * 1e3 + (tv.tv_usec / 1e3));
	else if (MICROSECOND == timecode)
		return (tv.tv_sec * 1e6 + tv.tv_usec);
	else
		exit_error("Wrong timecode");
	return (0);
}

/*
** @brief Spin-wait until all philosopher threads are ready to start
** @param table Pointer to the main table structure
** @note Polls all_threads_ready under table_mutex in a busy loop
** @note Called by each philo thread at the start of simulation()
** @see start_dinner() which sets all_threads_ready to true
*/
void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}
