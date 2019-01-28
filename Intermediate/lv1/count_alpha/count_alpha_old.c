/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 22:14:25 by chsu              #+#    #+#             */
/*   Updated: 2019/01/25 23:02:49 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	else
		return (c);
}

void	print_result(int *arr, int *sort)
{
	int	i = 0;

	while (sort[i] != 0)
	{
		if (i == 0)
		{
			printf("%i%c", arr[sort[i]], sort[i]);
		}
		else
		{
			printf(", %i%c", arr[sort[i]], sort[i]);
		}
		i++;
	}
}

void	count_alpha(char *s)
{
	int	arr[128] = {0};
	int	sort[27] = {0};
	int	i = 0, j;
	int	ae;
	int	tmp;

	while (s[i])
	{
		tmp = (int)to_lower(s[i]);
		if (tmp >= 'a' && tmp <= 'z')
		{
			arr[tmp] += 1;
			j = 0;
			ae = 0;
			while (sort[j] != 0)
			{
				if (sort[j] == tmp)
					ae = 1;
				j++;
			}
			if (ae == 0)
				sort[j] = tmp;
		}
		i++;
	}
	print_result(arr, sort);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
	return (0);
}
