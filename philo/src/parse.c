/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:52:02 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/05 13:02:29 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
** @brief Parse and validate command-line arguments into the table struct
** @param table Pointer to the table structure to populate
** @param argv Command-line arguments from main
** @return int 0 on success, 1 on invalid input
** @note Times are converted from milliseconds (input) to microseconds (* 1e3)
** @note max_nbr_meals is set to -1 if not provided (no meal limit)
** @warning Negative values and zero for nbr_philo are rejected
** @see ft_atol() for string-to-long conversion with validation
*/
int	input_parser(t_table *table, char **argv)
{
	table->nbr_philo = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1e3;
	table->time_to_eat = ft_atol(argv[3]) * 1e3;
	table->time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table->nbr_philo <= 0 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0)
		return (1);
	if (argv[5])
	{
		table->max_nbr_meals = ft_atol(argv[5]);
		if (table->max_nbr_meals <= 0)
			return (1);
	}
	else
		table->max_nbr_meals = -1;
	return (0);
}

/*
** @brief Check if a character is a digit (0-9)
** @param c The character to check
** @return true if c is between '0' and '9', false otherwise
*/
bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
** @brief Skip whitespace and sign, validate that the string is a number
** @param str The raw string to validate
** @return const char* Pointer to the first digit, NULL if invalid
** @note Accepts optional leading '+', rejects '-'
** @warning Returns NULL and prints error if negative or non-digit
*/
static const char	*input_validate(const char *str)
{
	const char	*number;
	int			i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		exit_error("Negative numbers not accepted");
		return (NULL);
	}
	if (!is_digit(str[i]))
	{
		exit_error("Not a digit");
		return (NULL);
	}
	number = &str[i];
	return (number);
}

/*
** @brief Convert a validated string to a long integer
** @param str The string to convert
** @return long The converted number, -1 on validation failure or overflow
** @note Rejects values greater than INT_MAX
** @warning Returns -1 on any error — caller must check for negative return
** @see input_validate() for the pre-validation step
** @see input_parser() which uses this to parse each argument
*/
long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = input_validate(str);
	if (!str)
		return (-1);
	while (is_digit(*str))
		num = num * 10 + (*str++ - '0');
	if (*str != '\0')
		return (-1);
	if (num > INT_MAX)
	{
		exit_error("Number bigger than int maximum");
		return (-1);
	}
	return (num);
}
