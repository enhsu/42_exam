/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:06:15 by chsu              #+#    #+#             */
/*   Updated: 2018/08/16 22:11:40 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	exam_putul(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	else if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	write(1, &c, 1);
}

void	exam_ulstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		exam_putul(s[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		exam_ulstr(av[1]);
	write(1, "\n", 1);
	return (0);
}
