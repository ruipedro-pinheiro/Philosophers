/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:49:35 by rpinheir          #+#    #+#             */
/*   Updated: 2025/10/01 16:00:49 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Verifie si un caractere est alphanumerique
** @param c Caractere a verifier (cast en int)
** @return int 1 si alphanumerique (a-z, A-Z, 0-9), 0 sinon
** @details Combine les tests ft_isalpha() || ft_isdigit()
** @note Utile pour valider des identifiants, noms de variables, etc.
** @see ft_isalpha pour tester uniquement les lettres
** @see ft_isdigit pour tester uniquement les chiffres
** @example ft_isalnum('a') = 1, ft_isalnum('5') = 1, ft_isalnum('@') = 0
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
