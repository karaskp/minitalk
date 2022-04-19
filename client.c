/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:00:04 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 16:45:33 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	sigusr1 == 1
	sigusr2 == 0
*/

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
	strtobits = asciitobinary(av[2],);
	/*
		y'a un pblm parce que jkompren ap si jrecois un str ou un char
	*/
	/*
		convert back to binary strtobits; (av2)
		
	*/
	//send back to server with ft_sendback(pid, strtobits);
	return (0);
}
