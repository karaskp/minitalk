/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 17:55:27 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	ft_server(int signum, siginfo_t *info, void *idk)
{
	pid_t	pid_client;

	(void)idk;
	pid_client = 0;
}*/

void	ft_server(int signum)
{
//	send signal with
	//signal(SIGUSR1, ft_server);
	ft_printf("in ft_server ! signum = %d\n", signum);
}

/*void	sig_child(int signum)
{
	ft_printf("signal received from parent : %d\n", signum);
	sleep(1);
	kill(getppid(), SIGUSR1);
}
*/
int	main(void)
{
	int			pid_serv;
//	struct	sigaction	s_sigact;
	

	pid_serv = (int)getpid();
	ft_printf("PID server : %d\n", pid_serv);
//	s_sigact.sa_sigaction = ft_server;
//	s_sigact.sa_flags = 0;
//	sigaction(SIGUSR1, &s_sigact, NULL);
//	sigaction(SIGUSR2, &s_sigact, NULL);
//	signal(SIGUSR2, ft_client);
	signal(SIGUSR1, ft_server);
//		kill(pid_serv, SIGUSR1);
//		ft_printf("parent waiting for answer\n");
	while (1)
		sleep(5);
	return (0);
}
