/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:07:39 by rpinheir          #+#    #+#             */
/*   Updated: 2025/09/30 14:21:39 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Verifie si un caractere fait partie de la table ASCII standard
** @param c Caractere a verifier (cast en int)
** @return int 1 si ASCII (0-127), 0 sinon
** @details La table ASCII standard contient 128 caracteres (7 bits)
** @note Caracteres > 127 sont de l'ASCII etendu ou UTF-8
** @warning Accepte les caracteres de controle (0-31) comme valides
** @see ft_isprint pour tester uniquement les caracteres imprimables
** @example ft_isascii(127) = 1, ft_isascii(128) = 0, ft_isascii(-1) = 0
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
