/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:37:38 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/03 13:13:50 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5)
	{
		printf("No enough arguments.\n Example: ./philo 5 800 200 200 [5]\n");
	}
	else if (argc > 6)
		printf("Too many arguments.\n Example: ./philo 5 800 200 200 [5]\n");
	input_parser(&table, argv);
	return (1);
}
