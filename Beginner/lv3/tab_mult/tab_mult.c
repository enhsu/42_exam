/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:08:59 by chsu              #+#    #+#             */
/*   Updated: 2018/12/10 23:12:14 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(int i)
{
	char	c;

	if (i >= 0)
		c = i % 10 + '0';
	if (i > 9)
		ft_putnum(i / 10);
	write(1, &c, 1);
}

void	show_result(int i, int num)
{
	ft_putnum(i);
	write(1, " x ", 3);
	ft_putnum(num);
	write(1, " = ", 3);
	ft_putnum(i * num);
	write(1, "\n", 1);
}

int		ft_atoi(char *s)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		num = 10 * num + (s[i] - '0');
		i++;
	}
	return (num);
}

void	tab_mult(char *s)
{
	int	num;
	int	i;

	num = ft_atoi(s);
	i = 1;
	while (i <= 9)
	{
		show_result(i, num);
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		tab_mult(av[1]);
	else
		write(1, "\n", 1);
	return (0);
}
