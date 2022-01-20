/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 07:37:26 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/01/19 14:56:55 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

extern int	g_checksum;

static	void	mt_kill(int pid, char *str)
{
	int		bites;
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		bites = 7;
		c = str[i];
		while (bites >= 0)
		{
			if (c >> bites & 1)
				kill(pid, SIGUSR2);
			else
				kill (pid, SIGUSR1);
			g_checksum++;
			usleep(800);
			bites--;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc != 3)
	{
		ft_putstr ("wrong the argument\n");
		return (0);
	}
	pid = ft_change_char_to_deci(argv[1]);
	mt_kill(pid, argv[2]);
	if ((g_checksum / g_checksum) == 1)
		ft_putstr("your data is received");
	else
		ft_putstr("your data is not received");
}
