/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:42:54 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/20 17:26:36 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_return_i(char *s1, char *set)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (set[k] != '\0')
	{
		if (set[k] == s1[i])
		{
			i++;
			k = 0;
		}
		else
			k++;
	}
	return (i);
}

static int	ft_return_j(char *s1, char *set)
{
	int	j;
	int	k;

	j = ft_strlen(s1);
	k = 0;
	while (set[k] != '\0' && j > 0)
	{
		if (set[k] == s1[j - 1])
		{
			j--;
			k = 0;
		}
		else
			k++;
	}
	return (j);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	if (!s1)
		return (NULL);
	else
	{
		i = ft_return_i(s1, set);
		j = ft_return_j(s1, set);
		if (j == 0)
			i = 0;
	}
	result = malloc((1 * (j - i)) + 1);
	if (!result)
		return (NULL);
	j = j - i;
	while (k < j)
		result[k++] = s1[i++];
	result[k] = '\0';
	return (result);
}
