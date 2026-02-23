/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:55:38 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/06 11:28:53 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Compare au maximum n caracteres de deux strings
** @param s1 Premiere string
** @param s2 Deuxieme string
** @param n Nombre maximum de caracteres a comparer
** @return int 0 si egales, difference du premier char different sinon
** @details Compare jusqu'a '\0' ou n caracteres, le premier atteint
** @note Retour < 0 si s1 < s2, > 0 si s1 > s2
** @see ft_memcmp pour comparer des zones memoire de taille fixe
** @example ft_strncmp("abc", "abd", 2) retourne 0 (compare que "ab")
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > 0)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
		n--;
	}
	return (0);
}
