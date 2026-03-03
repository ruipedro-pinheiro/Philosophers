/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:12:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/03 13:17:28 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	data_init(t_table *table)
{
	table->end_simulation = false;
	table->philos = safe_malloc(table->nbr_philo);
}
