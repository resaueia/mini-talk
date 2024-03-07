/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:53:02 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/05 21:13:10 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	break_char(int c, int pid)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if (c & 128 >> counter)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		counter++;
		usleep(600);
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
	break_char('\n', pid);
}
