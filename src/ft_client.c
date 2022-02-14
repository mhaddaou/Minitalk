/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:59:33 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/02/14 04:21:41 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_sendmsg(int pid, char *str_bytes)
{
	int	i;

	i = 0;
	while (str_bytes[i])
	{
		if (str_bytes[i] == '0')
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		i++;
		usleep(1500);
	}
}

static	char	*ft_conbin(char *s, int len, int i)
{
	char	*str;
	char	c;
	int		bites;

	str = (char *) malloc (len * 8 + 1);
	if (!str)
		return (NULL);
	str[len * 8] = '\0';
	while (len > 0)
	{
		bites = 8;
		c = s[len - 1];
		while (bites > 0)
		{
			if (c % 2 == 1)
				str[ft_strlen(s) * 8 - i] = '1';
			else
				str[ft_strlen(s) * 8 - i] = '0';
			c /= 2;
			bites--;
			i++;
		}
		len--;
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str_bytes;
	int		i;
	int		len;

	len = ft_strlen(argv[2]);
	i = 1;
	if (argc != 3)
	{
		ft_putstr_fd("wrong the argument\n", 2);
		return (EXIT_FAILURE);
	}
	pid = ft_change_char_to_deci(argv[1]);
	str_bytes = ft_conbin(argv[2], len, i);
	if (!str_bytes)
	{
		ft_putstr ("alloc failed");
		return (0);
	}
	ft_sendmsg(pid, str_bytes);
	free(str_bytes);
}
