/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:55:10 by rpinheir          #+#    #+#             */
/*   Updated: 2026/02/04 15:55:12 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Convertit une chaîne de caractères en entier
** @param str Chaîne de caractères a convertir
** @return int Valeur entière de la chaîne
** @details Étapes de conversion:
**          1. Skip les whitespaces (espace, tab, newline, etc.)
**          2. Détecte le signe optionnel (+/-)
**          3. Convertit les chiffres jusqu'au premier non-chiffre
** @note Whitespaces reconnus: ' ', '\t', '\n', '\v', '\f', '\r' (ASCII 9-13)
** @warning Ne gère pas l'overflow INT_MAX/INT_MIN - comportement indéfini
** @see ft_isdigit pour la detection des chiffres
** @example ft_atoi("  -42abc") retourne -42
** @example ft_atoi("   +123") retourne 123
*/
long long	ft_atoll(const char *str)
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
