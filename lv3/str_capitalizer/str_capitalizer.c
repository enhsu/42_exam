/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:09:04 by chsu              #+#    #+#             */
/*   Updated: 2018/08/10 15:46:26 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int		is_low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int		is_up(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	do_up(char c)
{
	return (c - ('a' - 'A'));
}

char	do_low(char c)
{
	return (c + ('a' - 'A'));
}

void	ft_cap(char *s)
{
	int	i;

	// first char
	if (is_low(s[0]))
		s[0] = do_up(s[0]);
	write(1, &s[0], 1);
	// start from second char
	i = 1;
	while (s[i])
	{
		if (is_space(s[i - 1]) && is_low(s[i]))
			s[i] = do_up(s[i]);
		else if (!is_space(s[i - 1]) && is_up(s[i]))
			s[i] = do_low(s[i]);
		write(1, &s[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_cap(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
