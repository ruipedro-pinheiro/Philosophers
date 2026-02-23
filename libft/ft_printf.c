/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinheir@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:15:40 by rpinheir          #+#    #+#             */
/*   Updated: 2025/12/04 17:29:41 by rpinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief Gere les conversions de format (%%,%c,%s,%p,%d,%i,%u,%x,%X)
** @param s Chaine de format avec '%' a l'index i
** @param i Position actuelle sur le '%'
** @param varg Liste d'arguments variables (va_list)
** @param count Nombre de caracteres deja imprimes
** @return int Nouveau count avec les caracteres ajoutes
** @details Lit s[i+1] pour determiner le type de conversion
** @note Utilise va_arg() pour extraire l'argument correspondant
** @see ft_printf qui appelle cette fonction
*/
int	var_handler(const char *s, int i, va_list varg, int count)
{
	if (s[i + 1] == '%')
		count += ft_putchar('%');
	else if (s[i + 1] == 'c')
		count += ft_putchar(va_arg(varg, int));
	else if (s[i + 1] == 's')
		count += ft_putstr(va_arg(varg, char *));
	else if (s[i + 1] == 'p')
		count += ft_displayptr(va_arg(varg, void *));
	else if ((s[i + 1] == 'i') || s[i + 1] == 'd')
		count += ft_putnbr(va_arg(varg, int));
	else if (s[i + 1] == 'u')
		count += ft_putnbr_unsigned(va_arg(varg, unsigned int));
	else if (s[i + 1] == 'x')
		count += ft_putnbr_hex_lowercase(va_arg(varg, unsigned int));
	else if (s[i + 1] == 'X')
		count += ft_putnbr_hex_uppercase(va_arg(varg, unsigned int));
	return (count);
}

/*
** @brief Reproduction de printf avec formats variables (variadic function)
** @param s Chaine de format avec specificateurs %X
** @param ... Arguments variables correspondant aux %X
** @return int Nombre total de caracteres imprimes
** @details Parse la chaine, si '%' trouve appelle var_handler(),
**          sinon affiche le caractere normalement
** @note Formats supportes: %% %c %s %p %d %i %u %x %X
** @warning Ne supporte pas les flags de formatage (width, precision, etc.)
** @see var_handler pour le traitement des conversions
** @example ft_printf("Hello %s, you are %d", "Pedro", 28);
*/
int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	varg;

	va_start(varg, s);
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count = var_handler(s, i, varg, count);
			i += 2;
			continue ;
		}
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
