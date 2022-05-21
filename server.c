/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 14:59:30 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	sigusr1 == 1
	sigusr2 == 0
*/
// pause() to change in sleep(5)
// usleep() to change in usleep(1000)

void    ft_server(int signum, siginfo_t *siginfo, void *empty)
{
    static int  ascii = 0;
    static int  power = 0;

    (void)empty;
    if (signum == SIGUSR1)
        ascii += (128 >> power);
    power += 1;
    if (power == 8)
    {
        ft_printf("%c", ascii);
        power = 0;
        ascii = 0;
    }
    if (siginfo->si_pid == 0)
        ft_error("Server didn't get client's PID\n");
    if (kill(siginfo->si_pid, SIGUSR2) == -1)
        ft_error("Error in returning signal!\n");
}

int main(int argc, char **argv)
{
    struct sigaction    sigac;

    (void)argv;
    if (argc != 1)
        ft_error("Error arguments\n");
    ft_printf("%d\n", getpid());
    sigemptyset(&sigac.sa_mask);
    //sigaddset(&sigac.sa_mask, SIGINT);
    //sigaddset(&sigac.sa_mask, SIGQUIT);
    sigac.sa_flags = SA_SIGINFO;
    sigac.sa_sigaction = ft_server;
    if ((sigaction(SIGUSR1, &sigac, 0)) == -1)
        ft_error("Error sigaction\n");
    if ((sigaction(SIGUSR2, &sigac, 0)) == -1)
        ft_error("Error sigaction\n");
    while (1)
        sleep(5);
    return (0);
}

/*
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
}*/
