/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 14:26:08 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server(int signum, siginfo_t *info, void *idk)
{
	pid_t	pid_client;

	(void)idk;
	pid_client = 0;
}

int	main(void)
{
	int			pid_serv;
	struct	sigaction	s_sigact;
	

	pid_serv = (int)getpid();
	//(converti en str, il faut un malloc de 13bytes (12 pr les digit et 1 pour \0)) 
	// avec du coup free de la mem non utilisée
	ft_printf("PID server : %d\n", pid_serv);
//	sigemptyset(&s_sigact.sa_mask);
//	s_sigact.sa_sigaction = ft_server;
//	s_sigact.sa_flags = 0;
//	sigaction(SIGUSR1, &s_sigact, NULL);
//	sigaction(SIGUSR2, &s_sigact, NULL);
	signal(SIGUSR1, ft_server);
	signal(SIGUSR2, ft_server);
}
