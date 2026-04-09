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

/*
** @brief Assign left and right forks to a philosopher
** @param philo Pointer to the philosopher to configure
** @param forks Array of all forks on the table
** @param position Index of this philosopher (0-based)
** @note Even-numbered philos swap fork order to prevent deadlock
** @note This ensures no two adjacent philos lock forks in the same order
** @see data_init() which calls philo_init() which calls this
*/
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

/*
** @brief Initialize all philosopher structs with default values and forks
** @param table Pointer to the main table structure
** @note Sets id (1-based), meals to 0, last_meal_time to 0
** @note last_meal_time is updated to time_start_sim in start_dinner()
** @see assign_forks() for fork assignment per philosopher
*/
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
		philo->time_to_die = table->time_to_die;
		philo->last_meal_time = 0;
		assign_forks(philo, table->forks, i);
	}
}

/*
** @brief Allocate memory, init all mutexes, and configure philosophers
** @param table Pointer to the table structure (already populated by parser)
** @return int Always returns 0
** @note Inits table_mutex, simulation_mutex, and one fork mutex per philo
** @warning safe_malloc does not exit on failure — potential NULL dereference
** @see cleanup() for the corresponding deallocation and mutex destroy
** @see philo_init() for philosopher struct initialization
*/
int	data_init(t_table *table)
{
	int	i;

	i = -1;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philo);
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philo);
	mutex_handler(&table->table_mutex, INIT);
	mutex_handler(&table->simulation_mutex, INIT);
	while (++i < table->nbr_philo)
		mutex_handler(&table->forks[i].fork, INIT);
	philo_init(table);
	return (0);
}
