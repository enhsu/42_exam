/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:42:46 by chsu              #+#    #+#             */
/*   Updated: 2018/08/10 14:20:27 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

void	ft_putword(char *s, int i, int j)
{
	while (i < j)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_lastword(char *s)
{
	int	i;
	int	j;
	int	last_white;

	i = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
		{
			j = i;
			while (!is_space(s[j]))
				j++;
			last_white = j;
			while (s[last_white] == ' ' || s[last_white] == '\t')
				last_white++;
			if (s[last_white] == '\0')
			{
				ft_putword(s, i, j);
				break ;
			}
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_lastword(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
