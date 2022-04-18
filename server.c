/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 12:43:31 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	getpid_server()
{

}

int	main(void)
{
	int			pid_serv;
	struct	sigaction	s_sigaction;
	

	pid_serv = (int)getpid();
	//(converti en str, il faut un malloc de 13bytes (12 pr les digit et 1 pour \0)) 
	// avec du coup free de la mem non utilisée
	ft_printf("PID server : %d\n", pid_serv);
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = 0;
	sigaction(SIGUSR1, ,);
	sigaction(SIGUSR2, ,);
}
