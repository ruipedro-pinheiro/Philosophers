/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:42:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/06 12:05:04 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Compare deux zones memoire octet par octet
** @param s1 Premiere zone memoire
** @param s2 Deuxieme zone memoire
** @param n Nombre d'octets a comparer
** @return int 0 si identiques, difference du premier octet different sinon
** @details Retourne (s1[i] - s2[i]) au premier octet different
** @note Compare en unsigned char pour eviter problemes de signe
** @see ft_strncmp pour comparer des strings (s'arrete au '\0')
** @example ft_memcmp("abc", "abd", 3) retourne -1 ('c' - 'd')
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	if (s1 == (void *)0 && s2 == (void *)0)
		return (*(int *)s2);
	while (i < n)
	{
		if ((unsigned char)tmp1[i] != (unsigned char)tmp2[i])
			return ((unsigned char)tmp1[i] - (unsigned char)tmp2[i]);
		i++;
	}
	return (0);
}
