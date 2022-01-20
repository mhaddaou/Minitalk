/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:53:47 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/01/19 14:58:17 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern int	g_checksum;

static void	handler_msg(int sig)
{
	static char	c = 0xff;
	static int	bites = 0;

	if (sig == SIGUSR1)
	{
		c ^= 128 >> bites;
		g_checksum++;
	}
	else
	{
		c |= 128 >> bites;
		g_checksum++;
	}
	if (++bites == 8)
	{
		ft_putchar(c);
		c = 0xff;
		bites = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr ("PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
	{
		signal(SIGUSR1, handler_msg);
		signal(SIGUSR2, handler_msg);
		pause();
	}
}
