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

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	return (NULL);
}

void	start_dinner(t_table *table)
{
	int	i;

	i = -1;
	if (table->max_nbr_meals == 0)
		return ;
	if (table->nbr_philo == 1)
	{
		// TODO
	}
	else
	{
		while (++i < table->nbr_philo)
			thread_handler(&table->philos[i].thread_id, simulation,
				&table->philos[i], CREATE);
		while (++i < table->nbr_philo)
			mutex_handler(table->mutex, INIT);
	}
	set_bool(&table->table_mutex, &table->all_threads_ready, true);
}
