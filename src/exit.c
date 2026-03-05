/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 12:07:08 by rpinheir          #+#    #+#             */
/*   Updated: 2026/03/05 13:25:59 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		exit_error("Malloc didn't work");
	return (ret);
}

int	exit_error(const char *msg)
{
	printf("Error: %s\n", msg);
	return (1);
}
