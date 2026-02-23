/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:59:27 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/06 09:05:07 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Calcule la longueur d'une string
** @param s String dont on veut la longueur
** @return size_t Nombre de caracteres avant le '\0'
** @details Parcourt la string jusqu'au '\0' terminal
** @note Le '\0' n'est pas compte dans la longueur
** @warning Ne verifie pas si s est NULL - segfault possible
** @example ft_strlen("hello") retourne 5
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
