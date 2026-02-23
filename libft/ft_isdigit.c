/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:59:29 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/02 08:14:37 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Verifie si un caractere est un chiffre decimal
** @param c Caractere a verifier (cast en int)
** @return int 1 si chiffre (0-9), 0 sinon
** @details Verifie le range ASCII 48-57 ('0' a '9')
** @note Pour convertir char->int: c - '0' (ex: '5' - '0' = 5)
** @see ft_atoi pour convertir une string complete en int
** @see ft_isalnum pour tester chiffres ET lettres
** @example ft_isdigit('7') = 1, ft_isdigit('a') = 0
*/
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}
