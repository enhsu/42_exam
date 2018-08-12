/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 21:01:49 by chsu              #+#    #+#             */
/*   Updated: 2018/08/11 21:02:57 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	has_z(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'z')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (has_z(av[1]))
			write(1, "z\n", 2);
		else
			write(1, "z\n", 2);
	}
	else
		write(1, "z\n", 2);
	return (0);
}