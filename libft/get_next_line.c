/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:43:36 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/26 15:49:59 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Lit le fichier et accumule les donnees dans le stash
** @param fd File descriptor a lire
** @param stash Pointeur vers le stash (buffer persistant)
** @details Lit BUFFER_SIZE octets a la fois, accumule dans stash
**          jusqu'a trouver un '\n' ou atteindre EOF
** @note En cas d'erreur, libere tout et met stash a NULL
** @see get_next_line qui appelle cette fonction
*/
void	read_to_stash(int fd, char **stash)
{
	char	*buffer;
	int		bytes_readed;
	char	*temp_stash;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(*stash), *stash = NULL, (void)0);
	while (gnl_find_char(*stash, '\n') == -1)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
			return (free(buffer), free(*stash), *stash = NULL, (void)0);
		if (bytes_readed == 0)
			break ;
		buffer[bytes_readed] = '\0';
		temp_stash = ft_strjoin(*stash, buffer);
		if (!temp_stash)
			return (free(buffer), free(*stash), *stash = NULL, (void)0);
		free(*stash);
		*stash = temp_stash;
	}
	free(buffer);
}

/*
** @brief Nettoie le stash apres extraction d'une ligne
** @param stash Buffer a nettoyer
** @details Deplace tout ce qui est apres le '\n' au debut du stash
** @note Garde le reste des donnees pour le prochain appel
** @example "ligne1\nligne2" devient "ligne2" apres clean
*/
void	clean_stash(char *stash)
{
	int	len;
	int	i;

	len = gnl_find_char(stash, '\n');
	i = 0;
	while (stash[len + 1 + i])
	{
		stash[i] = stash[len + 1 + i];
		i++;
	}
	stash[i] = '\0';
}

/*
** @brief Initialise un stash vide
** @param stash Parametre ignore (pour signature)
** @return char* Pointeur vers une string vide allouee "", NULL si echec
** @details Alloue 1 octet pour creer un point de depart vide
** @note Appele au premier appel de get_next_line
*/
char	*malloc_stash(char *stash)
{
	stash = malloc(sizeof(char) * 1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	return (stash);
}

/*
** @brief Extrait une ligne du stash
** @param stash Pointeur vers le buffer persistant
** @param len Position du '\n' (-1 si pas trouve)
** @return char* Ligne extraite avec '\n', NULL si stash vide ou erreur
** @details Si len == -1 (pas de '\n'), retourne tout le stash (EOF)
**          Sinon extrait jusqu'au '\n' inclus et clean le stash
*/
char	*extract_line(char **stash, int len)
{
	char	*line;

	if (len == -1)
	{
		if (!*stash || !(*stash)[0])
			return (free(*stash), *stash = NULL, NULL);
		line = ft_strdup(*stash);
		return (free(*stash), *stash = NULL, line);
	}
	line = malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (free(*stash), *stash = NULL, NULL);
	ft_strlcpy(line, *stash, len + 2);
	clean_stash(*stash);
	return (line);
}

/*
** @brief Lit et retourne la prochaine ligne d'un file descriptor
** @param fd File descriptor a lire (fichier, stdin, etc.)
** @return char* Ligne lue incluant '\n' (sauf EOF), NULL si fin ou erreur
** @details Utilise un static stash pour garder les donnees entre appels
**          Lit BUFFER_SIZE octets a la fois, accumule jusqu'a '\n'
** @note Chaque appel retourne une nouvelle ligne, a free() apres usage
** @warning BUFFER_SIZE doit etre > 0 et fd >= 0
** @see read_to_stash, extract_line, clean_stash (helpers)
** @example while ((line = get_next_line(fd))) { ... free(line); }
*/
char	*get_next_line(int fd)
{
	static char	*stash;
	int			len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc_stash(stash);
		if (!stash)
			return (NULL);
	}
	read_to_stash(fd, &stash);
	if (!stash)
		return (NULL);
	len = gnl_find_char(stash, '\n');
	return (extract_line(&stash, len));
}
