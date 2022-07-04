/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/04 20:54:43 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server(int signum, siginfo_t *info, void *context)
{
	static char			*str = "";
	static char			c = 0;
	static char			*tmp = "";
	static unsigned int	i = 0;
	static int		j = 0;
	static pid_t		pid_client;

	(void)context;
/*	str = malloc(1 * 1);
	if (!str)
		return ;
	str = '\0';*/
	if (!pid_client)
		pid_client = info->si_pid;
	if (signum == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
		//	str[j] = '\0';
			ft_printf("%s\n", str);
			//free(str);
			str = "";
			return ;
		}
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return ;
		tmp[0] = c;
		tmp[1] = '\0';
/*
		peut etre mieux avec un fonc ki reprend principe de strjoin mais juste pr un char 
		et comme ca quand c '\0' on free et on repart
*/
		str = ft_strjoin(str, tmp);
		free(tmp);
	//	ft_printf("%c", c);
		j++;
		c = 0;
		kill(pid_client, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_server;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
