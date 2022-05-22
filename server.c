/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/22 12:37:30 by mcouppe          ###   ########.fr       */
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
static void	ft_catch_signal(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int		i = 0;
	static pid_t		pid_client;

	(void)context;
	if (!pid_client)
		pid_client = info->si_pid;
	if (signo == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		kill(pid_client, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_catch_signal;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

/*

		USING SIGNAL////////////////////////////////////////////


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
		pause();
	return (0);
}*/
