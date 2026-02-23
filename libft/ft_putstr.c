/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:50:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:50:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Affiche une string sur stdout et retourne sa longueur
** @param s String a afficher
** @return int Nombre de caracteres affiches
** @details Si s est NULL, affiche "(null)" et retourne 6
** @note Comportement identique a printf("%s", s) avec NULL
** @see ft_putstr_fd version avec file descriptor configurable
** @see ft_strlen pour le calcul de longueur
*/
int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}
