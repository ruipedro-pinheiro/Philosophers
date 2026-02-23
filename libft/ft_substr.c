/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:25:21 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/26 14:25:29 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Extrait une sous-string d'une string
** @param s String source
** @param start Index de debut de la sous-string
** @param len Longueur max de la sous-string
** @return char* Nouvelle string extraite, NULL si echec
** @details Si start >= len(s), retourne une string vide ""
**          Si len depasse la fin de s, ajuste automatiquement
** @note La string retournee doit etre free() par l'appelant
** @warning Alloue de la memoire - penser a free()
** @example ft_substr("hello", 1, 3) retourne "ell"
*/
char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
