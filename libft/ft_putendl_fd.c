/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 17:05:47 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 17:05:47 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Ecrit une string suivie d'un newline sur un file descriptor
** @param s String a ecrire
** @param fd File descriptor cible
** @details Equivalent a ft_putstr_fd(s, fd) + write(fd, "\n", 1)
** @note Utile pour afficher des lignes completes
** @warning Ne verifie pas si s est NULL
** @see ft_putstr_fd version sans newline
** @example ft_putendl_fd("Error", 2); // affiche "Error\n" sur stderr
*/
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
