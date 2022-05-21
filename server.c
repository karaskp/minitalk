/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 18:15:13 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	sigusr1 == 0
	sigusr2 == 1
*/
/*char	*ft_addonechar(char *old, int bit)
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
}*/
static void	ft_getlen(int *countbit, char **str, int *len, int signum)
{
	static int	len_bis;

	len_bis = 0;
	if (signum == SIGUSR2)
		len_bis += ft_converttobit(2, *countbit);
	if (*countbit == 31)
	{
		*len = 1;
		*str = ft_calloc((len_bis + 1), (sizeof(char)));
		*countbit = 0;
		len_bis = 0;
		return ;
	}
	(*countbit)++;
}

static void	ft_reset(int *len, char **str, int *i)
{
	*len = 0; 
	if (str != NULL)
	{
		ft_putendl_fd(*str, 1);
		free(*str);
		*str = 0;
	}
	*i = 0;
}

void	ft_server(int signum)
{
	static char	*strinbits;
	static int	charinbit;
	static int	countbit;
	static int	len;
	static int	i;

	countbit = 0;
	len = 0;
	i = 0;
	strinbits = 0;
	charinbit = 0;
	if (!len)
		ft_getlen(&countbit, &strinbits, &len, signum);
	else
	{
		if (signum == SIGUSR2)
			charinbit += ft_converttobit(2, countbit);
		if (countbit == 7)
		{
			strinbits[i++] = charinbit;
			countbit = 0;
			if (charinbit == 0)
				return (ft_reset(&len, &strinbits, &i));
			charinbit = 0;
			return ;
		}
		countbit++;
	}
}

int	main(void)
{
	int			pid_serv;
	

	pid_serv = (int)getpid();
	ft_printf("PID server : %d\n", pid_serv);
	signal(SIGUSR1, ft_server);
	signal(SIGUSR2, ft_server);
	while (1)
		usleep(100);
}
