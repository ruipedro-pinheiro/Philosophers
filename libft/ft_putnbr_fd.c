/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 17:10:59 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 17:10:59 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Ecrit un entier sur un file descriptor (recursif)
** @param n Entier a afficher
** @param fd File descriptor cible
** @details Gere INT_MIN (-2147483648) en cas special (hardcode)
**          Sinon: affiche '-' si negatif, puis recursion digit par digit
** @note Recursion: divise par 10 jusqu'au dernier chiffre, puis remonte
** @warning INT_MIN doit etre traite separement car -INT_MIN overflow
** @see ft_putnbr version pour stdout avec retour du count
*/
void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			num = n + '0';
			write(fd, &num, 1);
		}
	}
}
