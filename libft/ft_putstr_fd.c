/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 16:53:52 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 16:53:52 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Ecrit une string sur un file descriptor
** @param s String a ecrire
** @param fd File descriptor cible
** @details Parcourt la string et ecrit caractere par caractere
** @warning Ne verifie pas si s est NULL - segfault possible
** @note Pour stderr (messages d'erreur), utiliser fd=2
** @see ft_putstr version simplifiee pour stdout avec retour
** @example ft_putstr_fd("Error\n", 2); // message d'erreur sur stderr
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
