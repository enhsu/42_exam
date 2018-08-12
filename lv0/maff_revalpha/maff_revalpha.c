/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 20:48:38 by chsu              #+#    #+#             */
/*   Updated: 2018/08/11 20:54:23 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char	c;
	char	upper;
	int		i;

	c = 'z';
	i = 0;
	while (i <= ('z' - 'a'))
	{
		if (i % 2 == 1)
		{
			upper = c - ('a' - 'A');
			write(1, &upper, 1);
		}
		else
			write(1, &c, 1);
		c--;
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
