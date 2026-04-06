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
#include <unistd.h>
#include <sys/time.h>

void	do_eat(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	// lock both forks for time_to_eat

	get_end_simulation(philo->table);
	if (simulation_finished(philo->table))
		return ;
	mutex_handler(&philo->left_fork->fork, LOCK);
	mutex_handler(&philo->right_fork->fork, LOCK);
	set_long(&philo->table->table_mutex, &philo->meals, philo->meals + 1);
	set_long(&philo->table->table_mutex, &philo->last_meal_time, timestamp);

	printf("%ld %ld is eating\n", timestamp, philo->id);
	mutex_handler(&philo->left_fork->fork, UNLOCK);
	mutex_handler(&philo->right_fork->fork, UNLOCK);
}

void	do_sleep(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	get_end_simulation(philo->table);
	if (simulation_finished(philo->table))
		return ;
	usleep(philo->table->time_to_sleep);
	printf("%ld %ld is sleeping\n", timestamp, philo->id);
}

void	do_think(t_philo *philo)
{
	long	timestamp;

	timestamp = get_time(MILLISECOND);
	get_end_simulation(philo->table);
	if (simulation_finished(philo->table))
		return ;
	printf("%ld %ld is thinking\n", timestamp, philo->id);
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
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->max_nbr_meals == 0 || table->max_nbr_meals <= 0)
	{
		printf("no max meals\n");
	}
	if (table->nbr_philo == 1)
	{
		thread_handler(&table->philos[0].thread_id, simulation,
			&table->philos[0], CREATE);
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
	table->time_start_sim = get_time(MILLISECOND);
	i = -1;
	while (++i < table->nbr_philo)
	{
		set_long(&table->table_mutex, &table->philos[i].last_meal_time, table->time_start_sim);
	}
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	printf("all philos are ready\n");

	i = -1;
	while (++i < table->nbr_philo)
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
}
