/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:37:38 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/05 13:26:19 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5)
	{
		exit_error("Not enough arguments.\nExample: ./philo 5 800 200 200 [5]");
		return (1);
	}
	else if (argc > 6)
	{
		exit_error("Too many arguments.\nExample: ./philo 5 800 200 200 [5]");
		return (1);
	}
	if (input_parser(&table, argv) != 0)
		return (1);
	if (data_init(&table) != 0)
		return (1);
	start_dinner(&table);
	free(table.philos);
	free(table.forks);
	return (0);
}
