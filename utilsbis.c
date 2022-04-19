/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:16:30 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 15:51:30 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_binarytoascii(char *strinbits, int power)
{
	int	result;
	int	power_tmp;
	int	result_tmp;
	int	i;

	i = (ft_strlen(strinbits) - 1);
	result = 0;
	result_tmp = 0;
	while (i >= 0)
	{
		if (strinbits[i] == '1')
		{
			power_tmp = power;
			if (power == 0 )
				result = 1;
			else
				result_tmp = 1;
			while (power_tmp-- > 0)
				result_tmp *=  2;
			result += result_tmp;
		}
		power++;
		i--;
	}
	return (result);
}

char	**asciitobinary(char *strtobits)
{
	int	i;
	int	j;
	int	size;
	char	**bitstr;

	i = 0;
	size = (ft_strlen(strtobits) * 8);
	
	bitstr = malloc(sizeof(char *) * size);
	if (!bitstr)
		return (NULL);
	while (strtobits[i])
	{
		bitstr[j] = malloc(sizeof(char) * 8 + 1);
		if (!bitstr[j])
			return (NULL);
		bitstr[j] = chartobinary(strtobits[i]);
		i++;
	}
	free(strtobits);
	return (bitstr);
}

char	*chartobinary(char c)
{
	if (c < 32 || c > 127)
	{
		ft_printf("error with char\n");
		return (NULL);
	}
	
}
