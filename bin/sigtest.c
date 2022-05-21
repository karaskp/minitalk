/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:52:02 by mcouppe           #+#    #+#             */
/*   Updated: 2022/05/21 16:51:49 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "lol.h"

void	printsigstr(int sig)
{
	if (sig == SIGUSR2)
	{

	}
	else if (sig == SIGUSR1)
	{

	}
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	if (pid == -1)
	{
		printf("error in pid \n");
		return (0);
	}
	else
		printf("%d\n", pid);
	signal(SIGUSR1, printsigstr);
	signal(SIGUSR2, printsigstr);
	while (1)
		usleep(1000)
//	return (EXIT_SUCCESS);
}
