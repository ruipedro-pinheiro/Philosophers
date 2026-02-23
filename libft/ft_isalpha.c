/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:54:03 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/01 11:52:17 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Verifie si un caractere est une lettre alphabetique
** @param c Caractere a verifier (cast en int)
** @return int 1 si lettre (a-z ou A-Z), 0 sinon
** @details Verifie les ranges ASCII: 65-90 (A-Z) et 97-122 (a-z)
** @note Ne detecte pas les lettres accentuees (e, a, etc.)
** @see ft_isalnum pour inclure aussi les chiffres
** @see ft_toupper, ft_tolower pour conversion de casse
** @example ft_isalpha('Z') = 1, ft_isalpha('3') = 0
*/
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
