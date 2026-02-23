/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:18:49 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/26 14:19:24 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Copie une string de maniere securisee (BSD)
** @param dst Buffer destination
** @param src String source a copier
** @param size Taille du buffer dst
** @return int Longueur de src (pour detecter troncation)
** @details Copie au max size-1 caracteres, garantit '\0' final
** @note Retour >= size signifie que src a ete tronquee
** @warning Si size == 0, ne copie rien mais retourne len(src)
** @see ft_strlcat pour concatenation securisee
** @see ft_strdup pour copie avec allocation
** @example Si retour >= size, la copie a ete tronquee
*/
int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
