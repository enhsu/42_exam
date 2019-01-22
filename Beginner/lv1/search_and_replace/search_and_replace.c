/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 21:39:21 by chsu              #+#    #+#             */
/*   Updated: 2018/08/16 22:03:45 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		input_check(char *s1, char *s2)
{
	if (s1[1] == '\0' && s2[1] == '\0')
		return (1);
	return (0);
}

void	exam_replace(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == av[2][0])
			write(1, &av[3][0], 1);
		else
			write(1, &av[1][i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		if (input_check(av[2], av[3]))
		{
			exam_replace(av);
		}
	}
	write(1, "\n", 1);
	return (0);
}
