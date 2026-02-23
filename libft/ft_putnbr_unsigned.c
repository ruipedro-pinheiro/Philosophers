/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:51:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:51:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Affiche un unsigned int sur stdout
** @param n Nombre non-signe a afficher
** @return int Nombre de caracteres affiches
** @details Recursion: divise par 10 jusqu'au dernier chiffre
** @note Utilisee par ft_printf pour %u
** @note Pas de gestion du signe car unsigned (toujours >= 0)
** @see ft_putnbr pour les int signes
** @example ft_putnbr_unsigned(4294967295) affiche "4294967295"
*/
int	ft_putnbr_unsigned(unsigned int n)
{
	char	num;
	int		count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		num = n + '0';
		write(1, &num, 1);
		count++;
	}
	return (count);
}
