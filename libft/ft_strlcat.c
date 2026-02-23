/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 09:58:50 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/26 14:18:21 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief Concatene src a dst de maniere securisee (BSD)
** @param dst Buffer destination (doit contenir une string)
** @param src String a ajouter
** @param size Taille totale du buffer dst
** @return int Longueur totale tentee: len(dst) + len(src)
** @details Ajoute src a la fin de dst, garantit '\0' final
**          Si size <= len(dst), retourne size + len(src)
** @note Retour > size signifie troncation
** @warning dst doit deja contenir une string valide (avec '\0')
** @see ft_strlcpy pour copie securisee
** @example Si retour >= size, la concatenation a ete tronquee
*/
int	ft_strlcat(char *dst, const char *src, int size)
{
	int	dst_len;
	int	src_len;
	int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
