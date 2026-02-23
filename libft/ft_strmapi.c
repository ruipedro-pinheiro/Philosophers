/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 16:11:51 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 16:11:51 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Applique une fonction a chaque char et cree une nouvelle string
** @param s String source (non modifiee)
** @param f Fonction a appliquer: char f(index, caractere)
** @return char* Nouvelle string avec les caracteres transformes, NULL si echec
** @details Alloue une nouvelle string et applique f a chaque char
** @note La string retournee doit etre free() par l'appelant
** @warning Alloue de la memoire - penser a free()
** @see ft_striteri version in-place (modifie s directement)
** @example ft_strmapi("abc", to_upper) pourrait retourner "ABC"
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		i;

	i = 0;
	string = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!string)
		return (NULL);
	while (s[i])
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
