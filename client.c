/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:53:02 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/02/28 17:53:45 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void	treat_char(char c, int pid)
{
	//write(1, "opa2", 4);
	while (c >= 0)
	{
		if (c >= 10)
		{
			kill(pid, SIGUSR1);
			c -= 10;
			//printf("Enviou sigusr1, c ficou: %d\n", c);
			usleep(250);
		}
		if (c >= 1 && c <= 9)
		{
			kill(pid, SIGUSR2);
			c -= 1;
			//write(1, "opa4", 4);
			usleep(250);
		}
		if (c == 0)
		{
			kill(pid, SIGINT);
			usleep(250);
			//write(1, "opa5", 4);
			//kill(pid, SIGKILL);
			//usleep(250);
			c--;
		}
	}
}

int     main(int argc, char **argv)
{
	//int pid = getpid();
        char *str;
	int pid;
	int i = 0;

        if (argc == 3)
        {
		str = argv[2];
		pid = atoi(argv[1]);
		write(1, "opa", 3);
		while (str[i])
		{
			treat_char(str[i], pid);
			i++;
		}
        }
}
