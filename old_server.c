/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:34 by mcouppe           #+#    #+#             */
/*   Updated: 2022/07/12 13:46:45 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*ft_lstnew(char c)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->charadd = c;
	return (lst);
}

void	ft_lstadd(t_list **lst, t_list *last, t_list *new)
{
	t_list	*head;

	head = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (last != NULL)
		head = last;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
	last = new;
}

char	*ft_getlst(t_list *lst)
{
	char	*result;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	i = 0;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	while (lst != NULL)
	{
		result[i++] = lst->charadd;
		lst = lst->next;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_server(int signum, siginfo_t *info, void *context)
{
	static char			c = 0;
	static unsigned int	i = 0;
	static pid_t		pid_client;
	static t_list	*head = NULL;
	static t_list	*last = NULL;
	char	*print;

	(void)context;
	if (!pid_client)
		pid_client = info->si_pid;
	if (signum == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			kill(pid_client, SIGUSR2);
			pid_client = 0;
			print = ft_getlst(head);
			ft_printf("%s\n", print);
			free(print);
			ft_lstclear(&head);
			last = NULL;
			head = NULL;
			return ;
		}
		ft_lstadd(&head, last, ft_lstnew(c));	
		c = 0;
		kill(pid_client, SIGUSR1);
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
