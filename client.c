/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:53:02 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/01 19:54:34 by rsaueia-         ###   ########.fr       */
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

void	break_char(int c, int pid)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if (c & 128 >> counter)
		{
			kill(pid, SIGUSR1);
		//	usleep(250);
		}
		else
		{
			kill(pid, SIGUSR2);
		//	usleep(250);
		}
		counter++;
		usleep(42);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
		return (0);
	str = argv[2];
	pid = ft_atoi(argv[1]);
	while (str[i])
	{
		break_char(str[i], pid);
		i++;
	}
}
