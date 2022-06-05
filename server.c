/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/06/05 19:16:10 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static unsigned int		i = 0;
	static pid_t		pid_client;

	(void)context;
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
			return ;
		}
		ft_printf("%c", c);
		c = 0;
		kill(pid_client, SIGUSR1);
	}
	else 
	{
		c = c << 1;
	}
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
