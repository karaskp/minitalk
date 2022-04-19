/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 13:19:51 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendback(int pid, char *strtobits)
{
	int	i;

	i = 0;
	if (!strtobits)
	{
		ft_printf("Error\nSignal lost\n");
		exit(EXIT_SUCCESS);
		return ;
	}
	while (strtobits[i] != '\0')
	{
		if (strtobits[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	char	*strtobits;
	int	i;

	(void)ac;
	i = 0;
	pid = ft_atoi(av[1]);
	strtobits = backtobinary()
	/*
		convert back to binary strtobits; (av2)
		
	*/
	//send back to server with ft_sendback(pid, strtobits);
	return (0);
}
