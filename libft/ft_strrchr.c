/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:35:42 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 08:58:06 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Recherche la derniere occurrence d'un caractere dans une string
** @param s String dans laquelle chercher
** @param c Caractere a rechercher (cast en char)
** @return char* Pointeur vers la derniere occurrence, NULL si non trouve
** @details Parcourt toute la string et garde la derniere position trouvee
** @note Si c == '\0', retourne un pointeur vers le '\0' final
** @see ft_strchr pour chercher la premiere occurrence
** @example ft_strrchr("hello", 'l') retourne pointeur vers le 2eme 'l'
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (last);
}
