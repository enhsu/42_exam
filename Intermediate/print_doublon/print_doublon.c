/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:09:40 by chsu              #+#    #+#             */
/*   Updated: 2019/01/21 23:09:43 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int	i = 0,
		j = 0;
	int	first = 1;

	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (first)
			{
				first = 0;
				printf("%i", a[i]);
			}
			else
				printf(" %i", a[i]);
			i++;
			j++;
		}
		else
		{
			if (a[i] > b[j])
				j++;
			else
				i++;
		}
	}
	printf("\n");
}
