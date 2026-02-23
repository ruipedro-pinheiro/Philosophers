/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:54:28 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 08:52:48 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Concatene deux strings en une nouvelle string allouee
** @param s1 Premiere string
** @param s2 Deuxieme string (ajoutee apres s1)
** @return char* Nouvelle string s1+s2, NULL si echec ou s1/s2 NULL
** @details Alloue len(s1) + len(s2) + 1 octets
** @note La string retournee doit etre free() par l'appelant
** @warning Alloue de la memoire - penser a free()
** @see ft_split pour l'operation inverse (decoupage)
** @example ft_strjoin("hello", " world") retourne "hello world"
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}
