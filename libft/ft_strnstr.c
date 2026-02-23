/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:36:22 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/26 14:19:42 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Recherche une sous-string dans les n premiers caracteres
** @param big String dans laquelle chercher
** @param little Sous-string a trouver
** @param len Nombre max de caracteres a parcourir dans big
** @return char* Pointeur vers le debut de little dans big, NULL si non trouve
** @details Si little est vide, retourne big
** @note Recherche limitee aux len premiers caracteres de big
** @see ft_strchr pour rechercher un seul caractere
** @example ft_strnstr("hello world", "wor", 11) retourne pointeur vers "world"
*/
char	*ft_strnstr(const char *big, const char *little, int len)
{
	int	i;
	int	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
