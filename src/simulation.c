/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:08:39 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 11:26:19 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	do_eat(t_philo *philo)
{
	long	meals;

	mutex_handler(&philo->left_fork->fork, LOCK);
	safe_print(philo, "has taken a fork");
	mutex_handler(&philo->right_fork->fork, LOCK);
	safe_print(philo, "has taken a fork");
	meals = get_long(&philo->table->table_mutex, &philo->meals);
	set_long(&philo->table->table_mutex, &philo->meals, meals + 1);
	set_long(&philo->table->table_mutex, &philo->last_meal_time,
		get_time(MICROSECOND));
	safe_print(philo, "is eating");
	usleep(philo->table->time_to_eat);
	mutex_handler(&philo->left_fork->fork, UNLOCK);
	mutex_handler(&philo->right_fork->fork, UNLOCK);
}

void	do_sleep(t_philo *philo)
{
	safe_print(philo, "is sleeping");
	usleep(philo->table->time_to_sleep);
}

void	do_think(t_philo *philo)
{
	safe_print(philo, "is thinking");
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
	int			i;
	pthread_t	monitor_thread;

	i = -1;
	while (++i < table->nbr_philo)
		thread_handler(&table->philos[i].thread_id, simulation,
			&table->philos[i], CREATE);
	table->time_start_sim = get_time(MICROSECOND);
	i = -1;
	while (++i < table->nbr_philo)
	{
		set_long(&table->table_mutex,
			&table->philos[i].last_meal_time, table->time_start_sim);
	}
	thread_handler(&monitor_thread, monitor, table, CREATE);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->nbr_philo)
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
	thread_handler(&monitor_thread, NULL, NULL, JOIN);
}
