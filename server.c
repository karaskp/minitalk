/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/19 12:52:54 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
	sigusr1 == 1
	sigusr2 == 0
*/

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
	static char	*strtobits;
	static int	countbit;

	countbit++;
	if (strtobits == NULL)
	{
		countbit = 1;
		strtobits = malloc(sizeof(char) * 1);
		if (!strtobits)
			return ;
		strtobits = "";
	}
	else
	{
		if (signum == SIGUSR1)
			strtobits = ft_addonechar(strtobits, 1);
		else
			strtobits = ft_addonechar(strtobits, 0);
	}
	if (countbit == 8)
	{
		/*
			free et print strtobits apres avoir convert back to ascii
			countbit = 0;
		*/
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
}
