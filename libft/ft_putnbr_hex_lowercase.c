/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lowercase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:52:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:52:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Affiche un unsigned int en hexadecimal lowercase
** @param n Nombre a afficher en hexa
** @return int Nombre de caracteres affiches
** @details Recursion: divise par 16, affiche avec base "0123456789abcdef"
** @note Utilisee par ft_printf pour %x
** @see ft_putnbr_hex_uppercase pour %X (majuscules)
** @example ft_putnbr_hex_lowercase(255) affiche "ff"
*/
int	ft_putnbr_hex_lowercase(unsigned int n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_putnbr_hex_lowercase(n / 16);
		count += ft_putnbr_hex_lowercase(n % 16);
	}
	else
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}
