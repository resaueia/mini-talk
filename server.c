/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:42 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/02/29 19:54:19 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void	write_name(int sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
	{
		i = i + 10;
	}
	else if (sig == SIGUSR2)
	{
		i = i + 1;
	}
	else if (sig == SIGINT)
	{
		printf("%c", i);
		i = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, write_name);
	signal(SIGUSR2, write_name);
	signal(SIGINT, write_name);
	printf("%d\n", getpid());
	while (1);
}
