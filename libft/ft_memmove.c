/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 08:29:45 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/06 09:37:57 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Copie n octets en gerant le chevauchement des zones
** @param dest Zone memoire de destination
** @param src Zone memoire source
** @param n Nombre d'octets a copier
** @return void* Pointeur vers dest
** @details Si dest < src: copie du debut vers la fin (normal)
**          Si dest > src: copie de la fin vers le debut (evite ecrasement)
** @note Plus lent que memcpy mais safe pour les overlaps
** @see ft_memcpy version plus rapide mais unsafe si overlap
** @example Utile pour decaler des elements dans un tableau
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		while (n--)
			*temp_dest++ = *temp_src++;
	}
	else
	{
		temp_dest = temp_dest + n - 1;
		temp_src = temp_src + n - 1;
		while (n--)
			*temp_dest-- = *temp_src--;
	}
	return (dest);
}
