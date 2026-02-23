/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:54:00 by rpinheir          #+#    #+#             */
/*   Updated: 2025/11/20 12:54:00 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Affiche une valeur en hexadecimal (helper recursif)
** @param n Valeur unsigned long a convertir et afficher
** @return int Nombre de caracteres affiches
** @details Recursion: divise par 16 jusqu'a n < 16, puis affiche
** @note Utilise la base "0123456789abcdef" (lowercase)
** @see ft_displayptr qui appelle cette fonction
*/
static int	ft_putptr_hex(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_putptr_hex(n / 16);
		count += ft_putptr_hex(n % 16);
	}
	else
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}

/*
** @brief Affiche une adresse memoire au format hexadecimal
** @param ptr Pointeur dont l'adresse doit etre affichee
** @return int Nombre de caracteres affiches (incluant "0x" ou "(nil)")
** @details Format de sortie: "0x" suivi de l'adresse en hexa lowercase
** @note Si ptr est NULL, affiche "(nil)" et retourne 5
** @see ft_putptr_hex helper pour la conversion hexa
** @see ft_printf flag %p utilise cette fonction
** @example ft_displayptr(&var) affiche "0x7ffd5e8b3a4c"
*/
int	ft_displayptr(void *ptr)
{
	int				count;
	unsigned long	address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	address = (unsigned long)ptr;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	count += ft_putptr_hex(address);
	return (count);
}
