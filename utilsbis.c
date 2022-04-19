/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:16:30 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 16:53:49 by mcouppe          ###   ########.fr       */
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

char	*asciitobinary(char *strtobits)
{
	int	i;
	int	j;
/*
	il faut peut etre que bitstr soit une static
*/
	char	*bitstr;

	i = 0;
	if (strtobits == NULL)
		return (NULL);
	bitstr = malloc(sizeof(char) * (8 * ft_strlen(strtobits)));
	if (!bitstr)
		return (NULL);
	while (strtobits[i] != '\0')
	{
		bitstr = chartobinary(strtobits[i], bitstr);
		/*
			ici il faudrait que bitstr soit += chartobinary 
			ou alors tab de char ** qu'on join apres
		*/
		i++;
		j++;
	}
	bitstr[j] = NULL;
	free(strtobits);
	return (bitstr);
}

char	*chartobinary(char c, char *binarystr)
{
	int	i;
	int	nbr;
/*
	ou alors un truc qui test ici si binary == NULL ou non et si non on ajoute a la fin
*/
	nbr = (int)c;
	i = 0;
	if (c < 32 || c > 127)
	{
		ft_printf("error with char\n");
		return (NULL);
	}
	while (nbr > 0 && i < 8)
	{
		if (nbr % 2 == 1)
			binarystr[i] = '1';
		else
			binarystr[i] = '0';
		i++;
		nbr /= 2;
	}
	binarystr[i] = '\0';
	return (binarystr);
}
