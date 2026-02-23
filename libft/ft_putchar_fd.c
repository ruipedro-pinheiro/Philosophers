/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 16:49:16 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 16:49:16 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Ecrit un caractere sur un file descriptor
** @param c Caractere a ecrire
** @param fd File descriptor (0=stdin, 1=stdout, 2=stderr)
** @details Utilise l'appel systeme write()
** @note fd=1 pour stdout, fd=2 pour stderr (messages d'erreur)
** @see ft_putchar version simplifiee pour stdout
** @example ft_putchar_fd('!', 2); // affiche '!' sur stderr
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
