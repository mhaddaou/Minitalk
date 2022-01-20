/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:00:03 by mhaddaou          #+#    #+#             */
/*   Updated: 2022/01/19 11:20:19 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_convert(char *s)
{
	int				j;
	int				i;
	unsigned char	c;

	j = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		c += j * (s[i] - '0');
		j *= 2;
		i--;
	}
	write(1, &c, 1);
}

static	char	*ft_orichar(char *str, char c)
{
	char	*temp;
	int		i;

	temp = malloc (ft_strlen(str) + 2);
	if (!temp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = c;
	temp[i + 1] = '\0';
	free(str);
	return (temp);
}

static	void	handler_msg(int sig)
{
	static int	bitcount;
	static char	*bits;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_orichar(bits, '1');
	else
		bits = ft_orichar(bits, '0');
	if (bitcount == 8)
	{
		ft_convert(bits);
		free(bits);
		bits = NULL;
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
