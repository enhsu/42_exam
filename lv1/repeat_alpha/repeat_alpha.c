/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:22:33 by chsu              #+#    #+#             */
/*   Updated: 2018/08/16 15:32:42 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_word(char c)
{
	int	times;

	if (c >= 'a' && c <= 'z')
		times = c - 'a' + 1;
	else if (c >= 'A' && c <= 'Z')
		times = c - 'A' + 1;
	else
		times = 1;
	while (times > 0)
	{
		write(1, &c, 1);
		times--;
	}
}

void	ex_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		print_word(s[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		ex_putstr(av[1]);
	write(1, "\n", 1);
}
