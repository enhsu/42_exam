/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:14:57 by chsu              #+#    #+#             */
/*   Updated: 2018/12/09 22:49:20 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int i)
{
	int	c;

	if (i == 2 || i == 3 || i == 5 || i == 7)
		return (1);
	c = 3;
	while (c <= i / 2)
	{
		if (i % c == 0)
			return (0);
		c++;
	}
	return (1);
}

void	fprime(int input, int c)
{
	if (is_prime(input))
		printf("%i", input);
	else
	{
		while (c < input / 2)
		{
			if (is_prime(c))
			{
				if (input % c == 0)
				{
					printf("%i*", c);
					fprime(input / c, c);
					break ;
				}
			}
			if (c % 2 == 0)
				c++;
			else
				c += 2;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]), 2);
	printf("\n");
	return (0);
}
