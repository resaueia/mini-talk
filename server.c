/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:42 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/01 19:54:03 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void	process_byte(int sig)
{
	static int	index = 0;
	static int	letter = 0;
	int	array[8];

	array[0] = 128;
	array[1] = 64;
	array[2] = 32;
	array[3] = 16;
	array[4] = 8;
	array[5] = 4;
	array[6] = 2;
	array[7] = 1;

	if (sig == SIGUSR1)
		letter = letter + array[index];
	else if (sig == SIGUSR2)
		letter = letter + 0;
	if (index == 7)
		//write(1, &letter, 1);
		printf("%c", letter);
	if (index == 8)
	{
		letter = 0;
		index = 0;
	}
	index++;
}

int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, process_byte);
	signal(SIGUSR2, process_byte);
	while (1) 
	{
		pause();
	}
	return (0);
}
