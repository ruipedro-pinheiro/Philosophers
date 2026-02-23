/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 12:22:53 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 12:22:53 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Compte le nombre de mots separes par un delimiteur
** @param s String a analyser
** @param c Caractere delimiteur
** @param count Compteur initial (generalement 0)
** @return int Nombre de mots trouves
** @details Utilise un flag inword pour detecter les transitions
** @note Fonction helper pour ft_split
*/
static int	ft_count(const char *s, char c, int count)
{
	int	inword;
	int	i;

	i = 0;
	inword = 0;
	while (s[i])
	{
		if (s[i] != c && !inword)
		{
			count++;
			inword = 1;
		}
		else if (s[i] == c)
		{
			inword = 0;
		}
		i++;
	}
	return (count);
}

/*
** @brief Libere un tableau de strings partiellement alloue
** @param ptr Tableau de strings a liberer
** @param index Nombre d'elements deja alloues
** @return char** Toujours NULL (pour retour direct)
** @details Libere chaque string jusqu'a index, puis le tableau
** @note Utilisee en cas d'echec d'allocation dans ft_split
*/
static char	**ft_free(char **ptr, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

/*
** @brief Extrait un mot a partir d'une position donnee
** @param s String source
** @param c Delimiteur de fin de mot
** @param start Index de debut du mot
** @return char* Nouveau mot alloue, NULL si echec
** @details Calcule la longueur jusqu'au prochain c ou fin de string
** @note Fonction helper pour ft_split
*/
static char	*ft_stringmanager(const char *s, char c, int start)
{
	int		len;
	char	*string;
	int		i;

	len = 0;
	while (s[start + len] && s[start + len] != c)
	{
		len++;
	}
	string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = s[start + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*
** @brief Decoupe une string en tableau de mots selon un delimiteur
** @param s String a decouper
** @param c Caractere delimiteur
** @return char** Tableau de strings termine par NULL, NULL si echec
** @details Les delimiteurs consecutifs sont ignores (pas de mots vides)
** @note Le tableau ET chaque string doivent etre free() apres usage
** @warning Alloue de la memoire - penser a tout free()
** @see ft_strjoin pour l'operation inverse
** @example ft_split("  hello  world  ", ' ') = ["hello", "world", NULL]
*/
char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = ft_count(s, c, 0);
	ptr = ft_calloc(count + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		while (s[j] == c)
			j++;
		ptr[i] = ft_stringmanager(s, c, j);
		if (!ptr[i])
			return (ft_free(ptr, i));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
