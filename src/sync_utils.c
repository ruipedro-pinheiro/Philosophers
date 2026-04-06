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
	long	nbr_philo_eaten;

	i = -1;

	while ( ++i < table->nbr_philo && nbr_philo_eaten <= table->nbr_philo)
	{
		meals = get_long(&table->simulation_mutex, &table->philos[i].meals);
		if (meals >= table->max_nbr_meals)
			nbr_philo_eaten++;
		else if (nbr_philo_eaten == table->nbr_philo)
		{
			set_bool(&table->simulation_mutex, &table->end_simulation, true);
			printf("Simulation ended because all philos finished eating \n");
			return true;
		}
	}
	return false;
}
