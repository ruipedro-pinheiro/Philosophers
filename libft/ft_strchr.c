/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:15:48 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 08:51:52 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** @brief Recherche la premiere occurrence d'un caractere dans une string
** @param s String dans laquelle chercher
** @param c Caractere a rechercher (cast en char)
** @return char* Pointeur vers le caractere trouve, NULL si non trouve
** @details Parcourt la string jusqu'au '\0' inclus
** @note Si c == '\0', retourne un pointeur vers le '\0' final
** @see ft_strrchr pour chercher la derniere occurrence
** @see ft_memchr pour chercher dans une zone memoire de taille n
** @example ft_strchr("hello", 'l') retourne pointeur vers premier 'l'
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
