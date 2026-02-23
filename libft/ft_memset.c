/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:30:16 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/02 07:56:22 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Remplit une zone memoire avec un octet specifique
** @param s Pointeur vers la zone memoire
** @param c Octet a ecrire (cast en unsigned char)
** @param n Nombre d'octets a remplir
** @return void* Pointeur vers s
** @details Ecrit l'octet c dans les n premiers octets de s
** @note Pour initialiser a zero, preferer ft_bzero
** @see ft_bzero equivalent a ft_memset(s, 0, n)
** @example ft_memset(buffer, 'A', 10) remplit de 'AAAAAAAAAA'
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (n > 0)
	{
		*(tmp++) = (unsigned char ) c;
		n--;
	}
	return (s);
}
