/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:16:30 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 15:17:00 by mcouppe          ###   ########.fr       */
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
