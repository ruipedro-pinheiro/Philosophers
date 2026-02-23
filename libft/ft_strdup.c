/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:09:35 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 08:52:23 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Duplique une string en allouant une nouvelle copie
** @param s String a dupliquer
** @return char* Nouvelle string allouee, NULL si echec malloc
** @details Alloue strlen(s) + 1 octets et copie s dedans
** @note La string retournee doit etre free() par l'appelant
** @warning Alloue de la memoire - penser a free()
** @see ft_strlcpy utilisee pour la copie
** @example char *copy = ft_strdup("hello"); // copy independante
*/
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}
