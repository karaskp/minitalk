/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:11:32 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 16:53:08 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_sendback(int pid, char *strtobits);
void	ft_server(int signum);

char	ft_binarytoascii(char *strinbits, int power);

char	*chartobinary(char c, char *binarystr);
char	*ft_addonechar(char *old, int bit);

char	**asciitobinary(char *strtobits);
int	ft_atoi(char *str);
int	ft_strlen(char *str);

#endif
