/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 17:46:35 by chsu              #+#    #+#             */
/*   Updated: 2018/08/16 16:23:18 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_double(char *s, int i, char c)
{
	int	tf;
	int	j;

	j = 0;
	tf = 0;
	while (j < i)
	{
		if (s[j] == c)
		{
			tf = 1;
			break ;
		}
		j++;
	}
	return (tf);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_union(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_double(s1, i, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!is_double(s1, ft_strlen(s1), s2[i]) && !is_double(s2, i, s2[i]))
			write(1, &s2[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
