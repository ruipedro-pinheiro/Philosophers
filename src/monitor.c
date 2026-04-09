/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:45:23 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 15:25:14 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
** @brief Check if all philosophers have eaten max_nbr_meals times
** @param table Pointer to the main table structure
** @return true if all philos reached max_nbr_meals, false otherwise
** @note Returns false immediately if max_nbr_meals is -1 (not specified)
** @note Sets end_simulation to true if all philos are full
** @warning Reads philo meals under simulation_mutex to avoid data races
** @see get_end_simulation() which calls this function each check cycle
*/
bool	are_philos_full(t_table *table)
{
	long	i;
	long	nbr_full_philo;
	long	meals;

	i = -1;
	nbr_full_philo = 0;
	if (table->max_nbr_meals == -1)
		return (false);
	while (++i < table->nbr_philo)
	{
		meals = get_long(&table->simulation_mutex, &table->philos[i].meals);
		if (meals >= table->max_nbr_meals)
		{
			set_bool(&table->simulation_mutex,
				&table->philos[i].finished_eating, true);
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

/*
** @brief Check each philosopher for death by starvation or meal completion
** @param table Pointer to the main table structure
** @note Compares current time - last_meal_time against time_to_die
** @note Death message is printed inside a table_mutex lock to prevent overlap
** @note end_simulation is set BEFORE the died printf to block safe_print
** @warning Must not be called from a philosopher thread (monitor only)
** @see are_philos_full() for the meal completion check
** @see safe_print() which checks simulation_finished before printing
*/
void	get_end_simulation(t_table *table)
{
	int		i;
	long	last_meal_time;
	long	time_to_die;

	time_to_die = get_long(&table->simulation_mutex,
			&table->philos[0].time_to_die);
	i = -1;
	while (++i < table->nbr_philo && !simulation_finished(table))
	{
		last_meal_time = get_long(&table->simulation_mutex,
				&table->philos[i].last_meal_time);
		if (get_time(MICROSECOND) - last_meal_time >= time_to_die)
		{
			mutex_handler(&table->table_mutex, LOCK);
			set_bool(&table->simulation_mutex, &table->end_simulation, true);
			printf("%ld %ld died\n",
				(get_time(MICROSECOND) - table->time_start_sim) / 1000,
				table->philos[i].id);
			mutex_handler(&table->table_mutex, UNLOCK);
			return ;
		}
		are_philos_full(table);
	}
}

/*
** @brief Monitor thread routine: polls for death or meal completion
** @param data Void pointer to the t_table struct (cast internally)
** @return void* Always returns NULL
** @note Checks every 500 microseconds for death detection within 10ms
** @note Runs independently from philosopher threads
** @see get_end_simulation() for the actual death/meal check logic
** @see start_dinner() where this function is passed to pthread_create
*/
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
