/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:26:56 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 08:59:02 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Verifie si un caractere appartient a un set
** @param c Caractere a verifier
** @param set String contenant les caracteres du set
** @return int 1 si c est dans set, 0 sinon
** @note Fonction helper pour ft_strtrim
*/
static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

/*
** @brief Supprime les caracteres d'un set au debut et a la fin d'une string
** @param s1 String a trimmer
** @param set Caracteres a supprimer
** @return char* Nouvelle string trimmee, NULL si echec
** @details Supprime depuis le debut jusqu'au premier char hors du set,
**          puis depuis la fin jusqu'au dernier char hors du set
** @note La string retournee doit etre free() par l'appelant
** @warning Alloue de la memoire - penser a free()
** @example ft_strtrim("  hello  ", " ") retourne "hello"
** @example ft_strtrim("xxhelloxx", "x") retourne "hello"
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	ptr = malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
