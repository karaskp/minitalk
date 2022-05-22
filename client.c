/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/22 12:36:48 by mcouppe          ###   ########.fr       */
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

static void	ft_receive(int signum)
{
	static int	received = 0;

	if (signum == SIGUSR1)
		++received;
	else
	{
		ft_printf("%d\n", received);
		exit(0);
	}
}

/*static void	ft_sender_bychar(int pid_serv, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c >> i & i)
			kill(pid_serv, SIGUSR2);
		else
			kill(pid_serv, SIGUSR1);
		pause();
		usleep(200);
	}
}
*/
static void	ft_sender(int pid_serv, char *str)
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

/*static int	check_pid(int pid_serv)
{
	int	i;

	i = 8;
	while (i-- && kill(pid_serv, SIGUSR1) == 0)
	{
		pause();
		usleep(200);
	}
	return (i == -1);
}*/

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
/*	if (!check_pid(pid_serv))
	{
		ft_printf("Error in pid\n");
		return (0);
	}*/
	ft_sender(pid_serv, av[2]);
	while (1)
		pause();
	return (0);
}

/*

		USING SIGNAL()///////////////////////////


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
}*/
