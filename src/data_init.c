/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:12:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/04 15:27:23 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int	nbr_philo;

	nbr_philo = philo->table->nbr_philo;
	philo->left_fork = &forks[position];
	philo->right_fork = &forks[(position + 1) % nbr_philo];
	if (philo->id % 2 == 0)
	{
		philo->left_fork = &forks[(position + 1) % nbr_philo];
		philo->right_fork = &forks[position];
	}
}

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nbr_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->finished_eating = false;
		philo->meals = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
	}
}

int	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philo);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philo);
	mutex_handler(&table->table_mutex, INIT);
	mutex_handler(&table->write_mutex, INIT);
	while (++i < table->nbr_philo)
	{
		mutex_handler(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
	return (0);
}
