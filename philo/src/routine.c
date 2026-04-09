/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:08:39 by rpinheir          #+#    #+#             */
/*   Updated: 2026/04/09 16:00:00 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
 *
 *
 *
 *
 *
 */
void	smart_sleep(long time, t_table *table)
{
	long	start;

	start = get_time(MICROSECOND);
	while (!simulation_finished(table)
		&& (get_time(MICROSECOND) - start) < time)
	{
		usleep(50);
	}
}

/*
** @brief Philosopher picks up forks, eats, then releases forks
** @param philo Pointer to the philosopher performing the action
** @note For 1 philo: locks only left fork and waits for death (only 1 fork)
** @note Even philos pick forks in reverse order to prevent deadlock
** @note Updates meals count and last_meal_time under simulation_mutex
** @warning Holds both fork mutexes during the entire eat duration (usleep)
** @see assign_forks() for the fork ordering strategy
** @see do_sleep() for the next action after eating
*/
void	do_eat(t_philo *philo)
{
	long	meals;

	if (simulation_finished(philo->table))
		return ;
	if (philo->table->nbr_philo == 1)
	{
		mutex_handler(&philo->left_fork->fork, LOCK);
		safe_print(philo, "has taken a fork");
		while (!simulation_finished(philo->table))
			usleep(500);
		mutex_handler(&philo->left_fork->fork, UNLOCK);
		return ;
	}
	mutex_handler(&philo->left_fork->fork, LOCK);
	safe_print(philo, "has taken a fork");
	mutex_handler(&philo->right_fork->fork, LOCK);
	safe_print(philo, "has taken a fork");
	meals = get_long(&philo->table->simulation_mutex, &philo->meals);
	set_long(&philo->table->simulation_mutex, &philo->meals, meals + 1);
	set_long(&philo->table->simulation_mutex, &philo->last_meal_time,
		get_time(MICROSECOND));
	safe_print(philo, "is eating");
	smart_sleep(philo->table->time_to_eat, philo->table);
	mutex_handler(&philo->left_fork->fork, UNLOCK);
	mutex_handler(&philo->right_fork->fork, UNLOCK);
}

/*
** @brief Philosopher sleeps for time_to_sleep microseconds
** @param philo Pointer to the philosopher performing the action
** @note Checks simulation_finished before sleeping to avoid unnecessary delay
** @see do_think() for the next action after sleeping
*/
void	do_sleep(t_philo *philo)
{
	if (simulation_finished(philo->table))
		return ;
	safe_print(philo, "is sleeping");
	smart_sleep(philo->table->time_to_sleep, philo->table);
}

/*
** @brief Philosopher thinks, with optional delay for scheduling fairness
** @param philo Pointer to the philosopher performing the action
** @note If time_to_eat > time_to_sleep, adds a usleep to balance scheduling
** @note This prevents starvation with odd numbers of philosophers
** @see do_eat() for the next action after thinking
*/
void	do_think(t_philo *philo)
{
	if (simulation_finished(philo->table))
		return ;
	safe_print(philo, "is thinking");
	if (philo->table->nbr_philo % 2 != 0)
	{
		if (philo->table->time_to_eat > philo->table->time_to_sleep)
			smart_sleep(philo->table->time_to_eat
				- philo->table->time_to_sleep, philo->table);
		else
			smart_sleep(500, philo->table);
	}
}

/*
** @brief Main philosopher thread routine: eat -> sleep -> think loop
** @param data Void pointer to the t_philo struct (cast internally)
** @return void* Always returns NULL
** @note Waits for all_threads_ready before starting the loop
** @note Loops until simulation_finished is set by the monitor
** @see start_dinner() where this function is passed to pthread_create
** @see monitor() which sets end_simulation to stop this loop
*/
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
