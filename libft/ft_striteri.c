/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.ch>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-09 16:25:24 by rpinheir          #+#    #+#             */
/*   Updated: 2025-10-09 16:25:24 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief Applique une fonction a chaque caractere d'une string (in-place)
** @param s String a modifier
** @param f Fonction a appliquer: f(index, &caractere)
** @details Modifie s directement (contrairement a ft_strmapi)
** @note La fonction f recoit l'index ET un pointeur vers le char
** @see ft_strmapi version qui cree une nouvelle string
** @example Convertir en uppercase: f(i, &c) { *c = toupper(*c); }
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
