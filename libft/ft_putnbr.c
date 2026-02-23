/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:00:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 13:00:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Calcule le nombre de chiffres d'un entier
** @param n Entier a mesurer
** @return int Nombre de caracteres (incluant le signe -)
** @details Pour 0 et negatifs, compte au moins 1
** @note Fonction helper pour ft_putnbr
*/
static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/*
** @brief Affiche un entier sur stdout et retourne sa longueur
** @param n Entier a afficher
** @return int Nombre de caracteres affiches
** @details Gere les nombres negatifs et INT_MIN
** @note Utilisee par ft_printf pour %d et %i
** @see ft_putnbr_fd version avec file descriptor
** @see ft_itoa pour convertir en string
*/
int	ft_putnbr(int n)
{
	int	len;

	len = ft_numlen(n);
	ft_putnbr_fd(n, 1);
	return (len);
}
