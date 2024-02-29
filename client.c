/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:53:02 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/02/29 17:01:02 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	index;
	int	signal;
	int	number;

	index = 0;
	signal = 1;
	number = 0;
	while ((nptr[index] > 8 && nptr[index] < 14) || nptr[index] == 32)
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			signal = -signal;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		number = (number * 10) + (nptr[index] - 48);
		index++;
	}
	number = number * signal;
	return (number);
}

void	treat_char(char c, int pid)
{
	while (c >= 0)
	{
		if (c >= 10)
		{
			kill(pid, SIGUSR1);
			c -= 10;
			usleep(250);
		}
		if (c >= 1 && c <= 9)
		{
			kill(pid, SIGUSR2);
			c -= 1;
			usleep(250);
		}
		if (c == 0)
		{
			kill(pid, SIGINT);
			usleep(250);
			c--;
		}
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		str = argv[2];
		pid = ft_atoi(argv[1]);
		while (str[i])
		{
			treat_char(str[i], pid);
			i++;
		}
	}
}
