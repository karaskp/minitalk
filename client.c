/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/22 13:56:51 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_receive(int signum)
{
	static int	received = 0;

	if (signum == SIGUSR1)
		++received;
	else
	{
		ft_printf("%d\n", received);
		exit(EXIT_SUCCESS);
	}
	(void)signum;
}

static void	ft_client(int pid_serv, char *str)
{
	int	i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid_serv, SIGUSR2);
			else
				kill(pid_serv, SIGUSR1);
			usleep(200);
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid_serv, SIGUSR1);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	unsigned int	pid_serv;

	if (ac != 3)
	{
		ft_printf("Wrong args\n");
		return (0);
	}
	pid_serv = ft_atoi(av[1]);
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	ft_client(pid_serv, av[2]);
	while (1)
		pause();
	return (0);
}
