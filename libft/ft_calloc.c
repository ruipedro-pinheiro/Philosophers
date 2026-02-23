/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:31:03 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/26 14:19:51 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Alloue et initialise a zero un bloc memoire
** @param nmemb Nombre d'elements a allouer
** @param size Taille de chaque element en octets
** @return void* Pointeur vers la memoire allouee, NULL si echec malloc
** @details Alloue nmemb * size octets puis initialise tout a zero
** @note Contrairement a malloc, la memoire est garantie initialisee a 0
** @warning Ne verifie pas l'overflow de nmemb * size
** @see ft_bzero utilisee pour l'initialisation
** @see malloc pour allocation sans initialisation
** @example int *arr = ft_calloc(10, sizeof(int)); // 10 ints a zero
*/
void	*ft_calloc(int nmemb, int size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
