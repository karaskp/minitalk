/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:18:27 by mcouppe           #+#    #+#             */
/*   Updated: 2021/12/17 20:13:35 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = size;
	}
	ptr = (char *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (size * nmemb));
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	int	*tab;
	int	*tab2;
	tab = ft_calloc(15, 4);
	tab2 = calloc(15,4);
	printf("mine : %d %d %d\n", tab[2], tab[0], tab[20]);
	printf("lib : %d %d %d", tab2[2], tab2[0], tab2[20]);
	void *d1 = ft_calloc(8539, 4);
	void *d2 = calloc(8539, 4);
	printf("memcmp : %d", memcmp(d1, d2, (8539 * 4)));
	return (0);
}*/
