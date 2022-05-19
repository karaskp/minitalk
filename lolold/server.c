/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 15:25:03 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	sigusr1 == 1
	sigusr2 == 0
*/

char	*ft_addonechar(char *old, int bit)
{
	int	i;
	int	size;
	char	*new;

	i = 0;
	size = ft_strlen(old);
	new = malloc(sizeof(char) * size + 2);
	if (!new)
		return (NULL);
	while (old[i] != '\0')
	{
		new[i] = old[i];
		i++;
	}
	if (bit == 1)
		new[i] = '1';
	else
		new[i] = '0';
	new[i + 1] = '\0';
	free(old);
	return (new);
}

void	ft_server(int signum)
{
	static char	*strinbits;
	static int	countbit;

	countbit++;
	if (strinbits == NULL)
	{
		countbit = 1;
		strinbits = malloc(sizeof(char) * 1);
		if (!strinbits)
			return ;
		strinbits = "";
	}
	if (signum == SIGUSR1)
		strinbits = ft_addonechar(strinbits, 1);
	else
		strinbits = ft_addonechar(strinbits, 0);
	if (countbit == 8)
	{
		ft_printf("%c",ft_binarytoascii(strinbits, 0));
		free(strinbits);
		countbit = 0;
	}
}

int	main(void)
{
	int			pid_serv;
	

	pid_serv = (int)getpid();
	ft_printf("PID server : %d\n", pid_serv);
	while (1)
	{
		signal(SIGUSR1, ft_server);
		signal(SIGUSR2, ft_server);
		pause();
	}
	return (0);
}