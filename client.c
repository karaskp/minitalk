/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 19:14:22 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	sigusr1 == 1
	sigusr2 == 0
*/
/*int main(int argc, char **argv)
{
    struct sigaction    sigac;

    received = 1;
    sigemptyset(&sigac.sa_mask);
    sigaddset(&sigac.sa_mask, SIGINT);
    sigaddset(&sigac.sa_mask, SIGQUIT);
    sigaddset(&sigac.sa_mask, SIGUSR1);
    sigac.sa_flags = SA_SIGINFO;
    sigac.sa_sigaction = ft_proto;
    if (sigaction(SIGUSR2, &sigac, NULL) == -1)
        ft_error("Error in client sigaction\n");
    if (ft_atoi(argv[1]) < 0)
        ft_error("Wrong PID!\n");
    if (argc == 3)
        ft_client(ft_atoi(argv[1]), argv[2]);
    else
        ft_error("Wrong arguments!\n");
    while (1)
        sleep (5);
    return (0);
}*/


void	ft_sendback(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(100);
	}
}

void	ft_sendlen(int pid, int len)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (len & 0x01)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		len = len >> 1;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*strtobits;

	if (ac != 3)
		return (-1);
	i = -1;
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (-1);
	strtobits = av[2];
	ft_sendlen(pid, (ft_strlen(strtobits)));
	while (strtobits[++i])
		ft_sendback(pid, strtobits[i]);
	//send back to server with ft_sendback(pid, strtobits);
	ft_sendback(pid, strtobits[i]);
	exit(EXIT_SUCCESS);
}
