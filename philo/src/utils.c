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

void	safe_print(t_philo *philo, char *msg)
{
	long	timestamp;

	timestamp = (get_time(MICROSECOND) - philo->table->time_start_sim) / 1000;
	mutex_handler(&philo->table->table_mutex, LOCK);
	if (simulation_finished(philo->table))
	{
		mutex_handler(&philo->table->table_mutex, UNLOCK);
		return ;
	}
	printf("%ld %ld %s\n", timestamp, philo->id, msg);
	mutex_handler(&philo->table->table_mutex, UNLOCK);
}

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		exit_error("Malloc didn't work");
	return (ret);
}

int	exit_error(const char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}

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

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}
