/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:37:38 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/03 16:28:30 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5)
	{
		printf("Error\nNot enough arguments.\nExample: ./philo 5 800 200 200 [5]\n");
		return (1);
	}
	else if (argc > 6)
	{
		printf("Error\nToo many arguments.\nExample: ./philo 5 800 200 200 [5]\n");
		return (1);
	}
	if (input_parser(&table, argv) != 0)
		return (1);
	
	if (data_init(&table) != 0)
		return (1);

	// TODO: Clean up resources before exiting when simulation ends
	free(table.philos);
	free(table.forks);

	return (0);
}
