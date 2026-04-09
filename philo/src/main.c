/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:37:38 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 12:05:35 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	cleanup(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nbr_philo)
	{
		mutex_handler(&table->forks[i].fork, DESTROY);
	}
	mutex_handler(&table->table_mutex, DESTROY);
	mutex_handler(&table->simulation_mutex, DESTROY);
	free(table->forks);
	free(table->philos);
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
		set_long(&table->simulation_mutex,
			&table->philos[i].last_meal_time, table->time_start_sim);
	}
	thread_handler(&monitor_thread, monitor, table, CREATE);
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
	i = -1;
	while (++i < table->nbr_philo)
		thread_handler(&table->philos[i].thread_id, NULL, NULL, JOIN);
	thread_handler(&monitor_thread, NULL, NULL, JOIN);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5)
	{
		exit_error("Not enough arguments.\nExample: ./philo 5 800 200 200 [5]");
		return (1);
	}
	else if (argc > 6)
	{
		exit_error("Too many arguments.\nExample: ./philo 5 800 200 200 [5]");
		return (1);
	}
	if (input_parser(&table, argv) != 0)
		return (1);
	if (data_init(&table) != 0)
		return (1);
	start_dinner(&table);
	cleanup(&table);
	return (0);
}
