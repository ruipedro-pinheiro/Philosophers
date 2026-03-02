/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:38:56 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/02 14:45:12 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <bits/pthreadtypes.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx				fork;
	long				fork_id;
}						t_fork;

typedef struct s_philo
{
	long				id;
	long				time_to_die;
	long				meals;
	bool				finished_eating;
	long				last_meal_time;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread_id;
}						t_philo;

typedef struct s_table
{
	t_philo				philos;
	t_fork				forks;
	long				nbr_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				max_nbr_meals;
	long				time_start_sim;
	bool				end_simulation;
}						t_table;

/*
 *			PROTOTYPE
 * */

long					ft_atol(const char *str);
long long				ft_atoll(const char *str);
bool					is_digit(char c);
void					exit_error(const char *msg);
void					input_parser(t_table *table, char **argv);
#endif
