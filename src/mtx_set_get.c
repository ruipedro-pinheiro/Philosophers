/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_set_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:34:24 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 11:14:47 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
** @brief Thread-safe setter for a boolean variable
** @param mutex Mutex protecting the variable
** @param dest Pointer to the boolean to modify
** @param value The new value to assign
*/
void	set_bool(t_mtx *mutex, bool *dest, bool value)
{
	mutex_handler(mutex, LOCK);
	*dest = value;
	mutex_handler(mutex, UNLOCK);
}

/*
** @brief Thread-safe getter for a boolean variable
** @param mutex Mutex protecting the variable
** @param value Pointer to the boolean to read
** @return bool The current value of the boolean
*/
bool	get_bool(t_mtx *mutex, bool *value)
{
	bool	ret;

	mutex_handler(mutex, LOCK);
	ret = *value;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

/*
** @brief Thread-safe setter for a long variable
** @param mutex Mutex protecting the variable
** @param dest Pointer to the long to modify
** @param value The new value to assign
*/
void	set_long(t_mtx *mutex, long *dest, long value)
{
	mutex_handler(mutex, LOCK);
	*dest = value;
	mutex_handler(mutex, UNLOCK);
}

/*
** @brief Thread-safe getter for a long variable
** @param mutex Mutex protecting the variable
** @param dest Pointer to the long to read
** @return long The current value of the long
*/
long	get_long(t_mtx *mutex, long *value)
{
	long	ret;

	mutex_handler(mutex, LOCK);
	ret = *value;
	mutex_handler(mutex, UNLOCK);
	return (ret);
}

/*
** @brief Check if the simulation has ended (death or all philos full)
** @param table Pointer to the main table structure
** @return bool true if end_simulation flag is set, false otherwise
** @note Reads end_simulation under simulation_mutex
** @see get_end_simulation() which sets end_simulation on death
** @see are_philos_full() which sets end_simulation on meal completion
*/
bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->simulation_mutex, &table->end_simulation));
}
