/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:35:24 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 11:37:39 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define	BUFF_SIZE 1
# define	MAX_FD 1024

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t i);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *str, const char *str1);
int					ft_strncmp(const char *str, const char *str1, size_t len);
int					ft_isdigit(int ch);
int					ft_isalpha(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *hs, const char *nd, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
void				*ft_memset(void	*dst, int ch, size_t len);
void				ft_bzero(void *str, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_escape(int ch);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *src, const char *dst, size_t dstsize);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_strclr(char *str);
void				ft_putchar(char ch);
void				ft_putchar_fd(char ch, int fd);
void				ft_putstr(char const *str);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				*ft_itoa(int i);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_strequ(char const *str1, char const *str2);
int					ft_strnequ(char const *str1, char const *str2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char ch);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_pow(int i, int n);
int					ft_chcmp(const char c1, const char c2);
int					ft_wordcount(char *str, const char ch);
char				*ft_trimch(const char *s, char ch);
char				**ft_split(char *str, char ch, char **array, int j);
int					ft_isint(char *str);
int					ft_absolute(int nbr);
int					get_next_line(int fd, char	**line);
#endif
