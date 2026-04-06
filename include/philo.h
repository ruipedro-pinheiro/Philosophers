/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:38:56 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/05 13:02:16 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#define _DEFAULT_SOURCE
# include "../libft/libft.h"
# include <bits/pthreadtypes.h>
# include <errno.h>
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

typedef enum opcode
{
	// mutexes
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	// threads
	CREATE,
	JOIN,
	DETACH,
}						t_opcode;

typedef enum e_timecode
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}						t_timecode;

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
	struct s_table		*table;
}						t_philo;

typedef struct s_table
{
	t_philo				*philos;
	t_fork				*forks;
	t_mtx				table_mutex;
	long				nbr_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				max_nbr_meals;
	long				time_start_sim;
	bool				all_threads_ready;
	bool				end_simulation;
}						t_table;

/*
 *			PROTOTYPE
 * */

long					ft_atol(const char *str);

bool					is_digit(char c);

int						exit_error(const char *msg);
int						input_parser(t_table *table, char **argv);
int						data_init(t_table *table);

void					*safe_malloc(size_t bytes);
void					thread_error_handler(int status, t_opcode opcode);
void					thread_handler(pthread_t *thread, void *(*foo)(void *),
							void *data, t_opcode opcode);
void					mutex_error_handler(int status, t_opcode opcode);
void					mutex_handler(t_mtx *mutex, t_opcode opcode);
void					wait_all_threads(t_table *table);

void					set_bool(t_mtx *mutex, bool *dest, bool value);
bool					get_bool(t_mtx *mutex, bool *value);
void					set_long(t_mtx *mutex, long *dest, long value);
long					get_long(t_mtx *mutex, long *value);
bool					simulation_finished(t_table *table);
long					get_time(t_timecode timecode);
void					start_dinner(t_table *table);
void                    get_end_simulation(t_table *table);


#endif
