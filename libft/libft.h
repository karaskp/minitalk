/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:19:09 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 14:56:44 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "ft_printf.h"

int		ft_atoi(char *str);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	ft_binarytoascii(char *strinbits, int power);

char	*asciitobinary(char *strtobits);
char	*chartobinary(char c, char *binarystr);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_itoa(int n);

char	**ft_split(char const *s, char c);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

void	ft_bzero(void *s, size_t n);
void	ft_error(char *to_print);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);


#endif
