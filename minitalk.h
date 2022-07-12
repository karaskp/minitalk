/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:11:32 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/12 17:36:01 by mcouppe          ###   ########.fr       */
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

typedef struct s_list
{
	char			charadd;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

#endif
