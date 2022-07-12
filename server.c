/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/12 15:32:03 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*join_one_char(char *str, char c)
{
	char	*result;
	int		i;
	int		check;

	i = 0;
	check = 0;
	if (ft_strlen(str) == 0)
		check++;
	result = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!result)
		return (NULL);
	while (str && str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	if (check == 0)
		free(str);
	return (result);
}

char	*print_n_free(char *str, int pid)
{
	kill(pid, SIGUSR2);
	ft_printf("%s\n", str);
	free(str);
	return ("");
}

static void	ft_server(int signum, siginfo_t *info, void *context)
{
	static char			*str = "";
	static char			c = 0;
	static unsigned int		i = 0;
	static pid_t			pid;

	(void)context;
	if (!pid)
		pid = info->si_pid;
	if (signum == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			str = print_n_free(str, pid);
			pid = 0;
			return ;
		}
		str = join_one_char(str, c);
		c = 0;
		kill(pid, SIGUSR1);
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_server;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID : %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
