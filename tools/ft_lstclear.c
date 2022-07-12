/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:24:36 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/12 18:30:16 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*lst_tmp;

	lst_tmp = *lst;
	if (!(*lst))
		return ;
	while (*lst != NULL)
	{
		lst_tmp = (*lst)->next;
		free((*lst));
		(*lst) = lst_tmp;
	}
	*lst = NULL;
}
