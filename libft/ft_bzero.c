/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:47:09 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/02 08:26:42 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Met a zero les n premiers octets d'une zone memoire
** @param s Pointeur vers la zone memoire a initialiser
** @param n Nombre d'octets a mettre a zero
** @details Parcourt la memoire octet par octet et ecrit '\0'
** @note Equivalent a memset(s, 0, n) mais sans valeur de retour
** @warning Ne verifie pas si s est NULL - segfault possible
** @see ft_memset pour une version plus generale
** @see ft_calloc qui utilise ft_bzero apres malloc
*/
void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)s = '\0';
		s++;
		n--;
	}
}
