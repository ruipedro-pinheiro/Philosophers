/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:06:52 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/06 09:35:13 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Copie n octets d'une zone memoire vers une autre
** @param dest Zone memoire de destination
** @param src Zone memoire source
** @param n Nombre d'octets a copier
** @return void* Pointeur vers dest
** @details Copie octet par octet de src vers dest
** @warning Comportement indefini si les zones se chevauchent!
** @note Utiliser ft_memmove si overlap possible
** @see ft_memmove pour copie safe avec overlap
** @see ft_strcpy pour copier des strings
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (!dest && !src)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	while (n--)
		*(tmp_dest++) = *(tmp_src++);
	return (dest);
}
