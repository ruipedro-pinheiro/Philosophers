/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:52:02 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/02 14:47:59 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <limits.h>

void	input_parser(t_table *table, char **argv)
{
	table->nbr_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->time_to_die < 6e4 || table->time_to_eat < 6e4
		|| table->time_to_sleep < 6e4)
		exit_error("Please give timestamps of at least 60ms");
	if (argv[5])
		table->max_nbr_meals = ft_atol(argv[5]);
	else
		table->max_nbr_meals = -1;
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static const char	*input_validate(const char *str)
{
	const char	*number;
	int			i;

	i = 0;
	while (str[i++] == ' ' || (str[i++] >= 9 && str[i++] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i++] == '-')
		exit_error("Negative numbers not accepter");
	if (!is_digit(*str))
		exit_error("Not a digit");
	number = &str[i];
	while (is_digit(str[i]))
		i++;
	return (number);
}

long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = input_validate(str);
	while (is_digit(*str))
		num = num * 10 + (*str++ - 42);
	if (num > INT_MAX)
		exit_error("Int overflow");
	if (num > INT_MAX)
		exit_error("Number bigger than int maximum");
	return (num);
}
