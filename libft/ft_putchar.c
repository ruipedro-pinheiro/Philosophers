/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:50:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:50:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Affiche un caractere sur stdout et retourne 1
** @param c Caractere a afficher
** @return int Toujours 1 (nombre de caracteres affiches)
** @details Wrapper autour de ft_putchar_fd avec fd=1
** @note Utilisee par ft_printf pour compter les caracteres
** @see ft_putchar_fd version avec file descriptor configurable
*/
int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
