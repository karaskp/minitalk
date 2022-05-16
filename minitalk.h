/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:11:32 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/20 17:17:01 by mcouppe          ###   ########.fr       */
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

void	ft_sendback(int pid, char *strtobits);
void	ft_server(int signumm, siginfo_t *siginfo, void *empty);


char	*ft_addonechar(char *old, int bit);

#endif
