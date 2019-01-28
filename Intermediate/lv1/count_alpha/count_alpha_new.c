/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:04:37 by chsu              #+#    #+#             */
/*   Updated: 2019/01/27 17:35:26 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_res(int *sort, int *arr)
{
	int	i = 0;
	int	flag = 0;

	while (sort[i] != 0)
	{
		if (flag == 0)
		{
			printf("%d%c", arr[sort[i]], sort[i]);
			flag = 1;
		}
		else
			printf(", %d%c", arr[sort[i]], sort[i]);
		i++;
	}
}

int		c_in_sort(int *sort, char c)
{
	int	i = 0;

	while (sort[i] != 0)
	{
		if (sort[i] == (int)c)
			return (1);
		i++;
	}
	return (0);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	else
		return (c);
}

void	count_a(char *s)
{
	int		arr[129] = {0};
	int		sort[27] = {0};
	int		i = 0, j = 0;
	char	c;

	while (s[i])
	{
		c = to_lower(s[i]);
		if (c >= 'a' && c <= 'z')
		{
			arr[(int)c] += 1;
			if (!c_in_sort(sort, c))
			{
				sort[j] = (int)c;
				j++;
			}
		}
		i++;
	}
	print_res(sort, arr);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_a(av[1]);
	printf("\n");
	return (0);
}
