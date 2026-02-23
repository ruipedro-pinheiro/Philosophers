/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:56:12 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/07 09:00:15 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Convertit une lettre minuscule en majuscule
** @param c Caractere a convertir (cast en int)
** @return int Caractere converti, ou c inchange si pas minuscule
** @details Si c est a-z, soustrait 32 (diff ASCII entre 'a' et 'A')
** @note Les caracteres non-alphabetiques sont retournes inchanges
** @see ft_tolower pour la conversion inverse
** @example ft_toupper('a') = 'A', ft_toupper('5') = '5'
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
