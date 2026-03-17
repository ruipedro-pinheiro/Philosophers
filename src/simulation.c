/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:08:39 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/05 15:05:47 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <sys/time.h>

void	do_eat(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	printf("%ld ", timestamp);
	printf("%ld ", philo->id);
	printf("is eating\n");
}

void	do_sleep(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	printf("%ld ", timestamp);
	printf("%ld ", philo->id);
	printf("is sleeping\n");
}

void	do_think(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	printf("%ld ", timestamp);
	printf("%ld ", philo->id);
	printf("is thinking\n");
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		do_eat(philo);
		do_sleep(philo);
		do_think(philo);
	}
	printf("end of simulation\n");
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->max_nbr_meals == 0)
	{
		printf("no meals\n");
		return ;
	}
	if (table->nbr_philo == 1)
	{
		thread_handler(&table->philos[i].thread_id, simulation,
			&table->philos[i], CREATE);
		mutex_handler(&table->table_mutex, INIT);
	}
	else
	{
		while (++i < table->nbr_philo)
			thread_handler(&table->philos[i].thread_id, simulation,
				&table->philos[i], CREATE);
		while (++i < table->nbr_philo)
			mutex_handler(&table->table_mutex, INIT);
	}
	printf("start of simulation\n");
	table->time_start_sim = get_time(SECOND);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	printf("all philos are ready\n");
	i = -1;
	while (++i < table->nbr_philo)
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
}
