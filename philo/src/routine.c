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
	usleep(philo->table->time_to_eat);
	mutex_handler(&philo->left_fork->fork, UNLOCK);
	mutex_handler(&philo->right_fork->fork, UNLOCK);
}

void	do_sleep(t_philo *philo)
{
	if (simulation_finished(philo->table))
		return ;
	usleep(philo->table->time_to_sleep);
	safe_print(philo, "is sleeping");
}

void	do_think(t_philo *philo)
{
	if (simulation_finished(philo->table))
		return ;
	safe_print(philo, "is thinking");
	if (philo->table->time_to_eat > philo->table->time_to_sleep)
		usleep(philo->table->time_to_eat - philo->table->time_to_sleep);
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
