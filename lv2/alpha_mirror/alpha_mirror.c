/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:13:21 by chsu              #+#    #+#             */
/*   Updated: 2018/08/10 09:32:38 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putmirror(char c)
{
	char	ret;

	ret = 0;
	if (c >= 'a' && c <= 'z')
	{
		ret = 'a' + ('z' - c);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		ret = 'A' + ('Z' - c);
	}
	else
		ret = c;
	write(1, &ret, 1);
}

int		main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i] != '\0')
		{
			ft_putmirror(av[1][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
