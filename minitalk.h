/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:11:32 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 17:12:08 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include <stddef.h>
# include "libft/libft.h"

void	ft_sendback(int pid, char c);
void	ft_server(int signum);


char	*ft_addonechar(char *old, int bit);

#endif
