/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:13:57 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/08 09:06:21 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Recherche un octet dans une zone memoire
** @param s Pointeur vers la zone memoire a scanner
** @param c Octet a rechercher (cast en unsigned char)
** @param n Nombre d'octets a scanner
** @return void* Pointeur vers le premier octet trouve, NULL si non trouve
** @details Scanne les n premiers octets de s a la recherche de c
** @note Compare des unsigned char, pas des int
** @see ft_strchr pour rechercher dans une string (s'arrete au '\0')
** @example ft_memchr("hello", 'l', 5) retourne pointeur vers premier 'l'
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return ((void *)tmp);
		tmp++;
	}
	return (NULL);
}
