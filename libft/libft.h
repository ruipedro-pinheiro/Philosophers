/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinheir <rpinhier@student.42Lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:55:31 by rpinheir          #+#    #+#             */
/*   Updated: 2026/02/04 15:55:31 by rpinheir         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*extract_line(char **stash, int len);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int chiffre);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, unsigned int len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, int len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *big, const char *little, int len);

int			ft_putchar(char c);
int			ft_putstr(char *s);
int			ft_putnbr(int n);
int			ft_putnbr_unsigned(unsigned int n);
int			ft_putnbr_hex_lowercase(unsigned int n);
int			ft_putnbr_hex_uppercase(unsigned int n);
int			ft_displayptr(void *ptr);
int			ft_strlen(const char *s);
int			gnl_find_char(const char *s, int c);
char		*ft_strchr(const char *s, int c);
int			ft_strlcpy(char *dst, const char *src, int size);
int			ft_printf(const char *s, ...);
int			var_handler(const char *s, int i, va_list varg, int count);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_strlcat(char *dst, const char *src, int size);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strncmp(const char *s1, const char *s2, int n);
int			ft_memcmp(const void *s1, const void *s2, int n);
int			ft_strfree(char **str);

long long	ft_atoll(const char *nptr);

void		*ft_calloc(int nmemb, int size);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_memset(void *s, int c, int n);
void		ft_bzero(void *s, int n);
void		*ft_memcpy(void *dest, const void *src, int n);
void		*ft_memmove(void *dest, const void *src, int n);
void		*ft_memchr(const void *s, int c, int n);

#endif
