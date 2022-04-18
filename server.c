/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 11:47:25 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

pid_t	getpid_server()
{

}

int	main(void)
{
	int	pid_serv;

	pid_serv = (int)getpid();
	//(converti en str, il faut un malloc de 13bytes (12 pr les digit et 1 pour \0)) 
	// avec du coup free de la mem non utilisée
}
