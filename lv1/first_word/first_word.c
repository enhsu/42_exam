/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:06:50 by chsu              #+#    #+#             */
/*   Updated: 2018/12/10 11:10:44 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	first_w(char *s)
{
	int	i;

	i = 0;
	while (s[i] && is_space(s[i]))
		i++;
	while (s[i] && !is_space(s[i]))
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		first_w(av[1]);
	write(1, "\n", 1);
	return (0);
}
