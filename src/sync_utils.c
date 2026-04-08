/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:52:41 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/04 15:57:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->all_threads_ready))
		;
}

bool	are_philos_full(t_table *table)
{
	long	i;
	long	meals;
	long	nbr_full_philo;

	i = -1;
	meals = 0;
	nbr_full_philo = 0;

	while (++i <= table->nbr_philo && nbr_full_philo < table->nbr_philo)
	{
		if (table->philos[i].meals >= table->max_nbr_meals && !table->philos[i].finished_eating)
		{
			table->philos[i].finished_eating = true;
			nbr_full_philo++;
		}
		if (nbr_full_philo >= table->nbr_philo)
		{
				set_bool(&table->simulation_mutex, &table->end_simulation, true);
				printf("Simulation ended because all philos finished eating \n");
				return true;
		}
	}
	return false;
}
