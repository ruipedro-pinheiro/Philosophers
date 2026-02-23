/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 15:08:39 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 15:08:39 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Compte le nombre de chiffres d'un entier
** @param chiffre Entier dont on veut compter les chiffres
** @return int Nombre de caracteres necessaires (incluant le signe -)
** @details Pour 0 et negatifs, compte au moins 1 pour le '0' ou le '-'
** @note Fonction helper pour ft_itoa
*/
static int	ft_count(int chiffre)
{
	int	count;

	count = 0;
	if (chiffre <= 0)
		count = 1;
	while (chiffre != 0)
	{
		chiffre = chiffre / 10;
		count++;
	}
	return (count);
}

/*
** @brief Convertit un entier en chaine de caracteres
** @param chiffre Entier a convertir
** @return char* Nouvelle string allouee representant l'entier, NULL si echec
** @details Utilise un long pour gerer INT_MIN (-2147483648)
** @note La string retournee doit etre free() par l'appelant
** @warning Alloue de la memoire - penser a free()
** @see ft_atoi pour l'operation inverse (string -> int)
** @example ft_itoa(-42) retourne "-42"
** @example ft_itoa(0) retourne "0"
*/
char	*ft_itoa(int chiffre)
{
	int		len;
	char	*string;
	long	num;

	len = ft_count(chiffre);
	string = ft_calloc(len + 1, sizeof(char));
	if (!string)
		return (NULL);
	string[len] = '\0';
	num = chiffre;
	if (num == 0)
		string[0] = '0';
	else if (num < 0)
	{
		string[0] = '-';
		num = -num;
	}
	len--;
	while (num > 0)
	{
		string[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (string);
}
