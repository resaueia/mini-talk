/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:40:41 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/10/30 19:36:06 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*This function receives a char type variable and transforms it into
an int type variable via a mathematical logic. It traverses the given string
and checks for white spaces, checks for a signal - be it negative or positive -
and behaves accordingly.*/
/*
#include <stdio.h>
int	main(void)
{
	printf("%i\n", ft_atoi(" ---+--+1234ab567"));
	printf("%i\n", ft_atoi(" ---+--+12agh34ab567"));
	printf("%i\n", ft_atoi(" 1234567"));
	printf("%i\n", ft_atoi("+1234567"));
	printf("%i\n", ft_atoi("-567"));
}
*/
