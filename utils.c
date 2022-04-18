/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:05:35 by mcouppe           #+#    #+#             */
/*   Updated: 2022/04/18 11:05:41 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, (ft_strlen(str));
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr < 10)
		ft_putchar_fd((nbr + '0'), fd);
	if (nbr >= 10)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putchar_fd(((nbr % 10) + '0'), fd);
	}
}

