/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 23:12:11 by chsu              #+#    #+#             */
/*   Updated: 2018/08/16 23:12:31 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	exam_putword(char *s, int i, int j)
{
	while (i < j)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	exam_last(char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (s[i])
	{
		if (i == 0 || (is_space(s[i - 1]) && !is_space(s[i])))
		{
			j = i;
			while (!is_space(s[j]) && s[j] != '\0')
				j++;
			k = j;
			while (is_space(s[k]) && s[j] != '\0')
				k++;
			if (s[k] == '\0')
				exam_putword(s, i, j);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		exam_last(av[1]);
	write(1, "\n", 1);
	return (0);
}
