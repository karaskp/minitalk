/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 17:32:27 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client(int signum)
{
/*	envoyer la char to_send au pid_server
 *
 * */
	ft_printf("inside client ! signum = %d\n", signum);
}

int	main(int ac, char **av)
{
	int	pid;
	char	*str;
	int	i;

	(void)ac;
	i = 0;
	str =  "Hello World";
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR2);
	while (str[i] != '\0')
	{
		ft_printf("%c", str[i]);
		kill(pid, SIGUSR1);
	}
	ft_printf("\n");
	kill(pid, SIGTERM);
	return (0);
}
