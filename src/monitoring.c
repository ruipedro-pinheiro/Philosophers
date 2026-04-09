/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:45:23 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 14:41:56 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	are_philos_full(t_table *table)
{
	long	i;
	long	nbr_full_philo;

	i = -1;
	nbr_full_philo = 0;
	if (table->max_nbr_meals == -1)
		return (false);
	while (++i < table->nbr_philo)
	{
		if (table->philos[i].meals >= table->max_nbr_meals)
		{
			table->philos[i].finished_eating = true;
			nbr_full_philo++;
		}
	}
	if (nbr_full_philo >= table->nbr_philo)
	{
		set_bool(&table->simulation_mutex, &table->end_simulation, true);
		return (true);
	}
	return (false);
}

void	get_end_simulation(t_table *table)
{
	int		i;
	long	last_meal_time;
	long	time_to_die;

	time_to_die = get_long(&table->table_mutex, &table->philos[0].time_to_die);
	i = -1;
	while (++i < table->nbr_philo && !simulation_finished(table))
	{
		last_meal_time = get_long(&table->table_mutex,
				&table->philos[i].last_meal_time);
		if (get_time(MICROSECOND) - last_meal_time >= time_to_die)
		{
			printf("%ld %ld died\n",
				(get_time(MICROSECOND) - table->time_start_sim) / 1000,
				table->philos[i].id);
			set_bool(&table->simulation_mutex, &table->end_simulation, true);
			return ;
		}
		are_philos_full(table);
	}
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	while (!simulation_finished(table))
	{
		get_end_simulation(table);
		usleep(500);
	}
	return (NULL);
}
