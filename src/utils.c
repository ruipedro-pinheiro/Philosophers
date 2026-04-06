/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:07:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/05 13:25:59 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

void	get_end_simulation(t_table *table)
{
	int		i;
	long	last_meal_time;
	long	time_to_die;

	time_to_die = get_long(&table->table_mutex, &table->philos[0].time_to_die);
	last_meal_time = get_long(&table->table_mutex,
			&table->philos[0].last_meal_time);
	i = -1;
	while (++i < table->nbr_philo && table->end_simulation == false)
	{
		if (get_time(MILLISECOND) - last_meal_time >= time_to_die)
		{
			printf("Philo %ld should die because he havent eat\n", table->philos->id);
			set_bool(&table->table_mutex, &table->end_simulation, true);
			return ;
		}
		if (table->philos[i].meals >= table->max_nbr_meals)
			set_bool(&table->simulation_mutex, &table->end_simulation, true);
	}
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
