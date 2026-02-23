/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:19:18 by rpinheir          #+#    #+#             */
/*   Updated: 2025/09/30 14:21:22 by rpinheir         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Verifie si un caractere est imprimable (visible a l'ecran)
** @param c Caractere a verifier (cast en int)
** @return int 1 si imprimable (32-126), 0 sinon
** @details Range ASCII: espace (32) jusqu'au tilde ~ (126)
** @note Exclut les caracteres de controle (0-31) et DEL (127)
** @warning L'espace (32) est considere imprimable meme s'il est "invisible"
** @see ft_isascii pour tester tout l'ASCII incluant controles
** @example ft_isprint(' ') = 1, ft_isprint('\n') = 0, ft_isprint('~') = 1
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
