/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 20:13:36 by chsu              #+#    #+#             */
/*   Updated: 2019/01/26 20:32:52 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void	check_fill(char **tab, t_point size, t_point begin, char replace)
{
	t_point	point;

	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == replace)
	{
		tab[begin.y][begin.x + 1] = 'F';
		point.x = begin.x + 1;
		point.y = begin.y;
		check_fill(tab, size, point, replace);
	}
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == replace)
	{
		tab[begin.y][begin.x - 1] = 'F';
		point.x = begin.x - 1;
		point.y = begin.y;
		check_fill(tab, size, point, replace);
	}
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == replace)
	{
		tab[begin.y + 1][begin.x] = 'F';
		point.x = begin.x;
		point.y = begin.y + 1;
		check_fill(tab, size, point, replace);
	}
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == replace)
	{
		tab[begin.y - 1][begin.x] = 'F';
		point.x = begin.x;
		point.y = begin.y - 1;
		check_fill(tab, size, point, replace);
	}
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	replace = tab[begin.y][begin.x];

	tab[begin.y][begin.x] = 'F';
	check_fill(tab, size, begin, replace);
}
