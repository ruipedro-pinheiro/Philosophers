/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:07:27 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 09:00:01 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Convertit une lettre majuscule en minuscule
** @param c Caractere a convertir (cast en int)
** @return int Caractere converti, ou c inchange si pas majuscule
** @details Si c est A-Z, ajoute 32 (diff ASCII entre 'A' et 'a')
** @note Les caracteres non-alphabetiques sont retournes inchanges
** @see ft_toupper pour la conversion inverse
** @example ft_tolower('A') = 'a', ft_tolower('5') = '5'
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
