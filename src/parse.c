/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:52:02 by rpinheir          #+#    #+#             */
/*   Updated: 2026/02/25 14:20:28 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	input_validate(int argc, char **argv)
{
	int		i;
	char	**matrix;

	matrix = argv;
	i = 1;
	while (argv[i] && i <= argc)
	{
		ft_printf("%d", matrix[i]);
		write(1, &matrix[i], 10);
		i++;
	}
	return (true);
}
