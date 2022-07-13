/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/13 20:37:56 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sent(int signum)
{
	static int	received = 0;

	if (signum == SIGUSR1)
		++received;
	else
	{
		(void)signum;
		ft_printf("%d\n", received);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_client(int pid_serv, char *str)
{
	unsigned int	g;
	unsigned int	i;
	unsigned char	c;

	g = -1;
	while (str && str[++g])
	{
		i = 8;
		c = str[g];
		while (i-- > 0)
		{
			if (c >> i & 1)
				kill(pid_serv, SIGUSR2);
			else
				kill(pid_serv, SIGUSR1);
			usleep(150);
	//		usleep(200);
	//		usleep(200);
	//		usleep(200);
		}
		i++;
	}
	i = 8;
	while (i-- > 0)
	{
		kill(pid_serv, SIGUSR1);
		usleep(150);
	//	usleep(200);
	//	usleep(200);
	//	usleep(200);
	}
}

int	main(int ac, char **av)
{
	unsigned int	pid_serv;

	if (ac != 3)
	{
		ft_putendl_fd("Error with arguments", 2);
		return (1);
	}
	pid_serv = ft_atoi(av[1]);
	if (pid_serv < 2)
	{
		ft_putendl_fd("Error with PID number", 2);
		return (1);
	}
	signal(SIGUSR1, ft_sent);
	signal(SIGUSR2, ft_sent);
	ft_client(pid_serv, av[2]);
	while (1);
	return (0);
}
