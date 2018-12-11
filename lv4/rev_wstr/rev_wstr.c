/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:50:25 by chsu              #+#    #+#             */
/*   Updated: 2018/12/10 23:51:21 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	print_word(char *s, int i, int is_last)
{
	while (s[i] && !ft_isspace(s[i]))
	{
		write(1, &s[i], 1);
		i++;
	}
	if (!is_last)
		write(1, " ", 1);
}

void	rev_wstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > -1)
	{
		if (ft_isspace(s[i]))
			print_word(s, i + 1, 0);
		if (i == 0)
			print_word(s, i, 1);
		i--;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
