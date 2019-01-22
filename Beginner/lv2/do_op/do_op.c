/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:52:50 by chsu              #+#    #+#             */
/*   Updated: 2018/08/10 10:28:18 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	op(char c)
{
	return (c == '+' || c == '-' || c == '*' ||
			c == '/' || c == '%');
}

int	is_op(char *s)
{
	if (s[1] == '\0')
	{
		if (op(s[0]))
		{
			return (1);
		}
	}
	return (0);
}

int	do_op(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	else if (op == '-')
		return (a - b);
	else if (op == '*')
		return (a * b);
	else if (op == '/')
		return (a / b);
	else
		return (a % b);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	res;

	if (ac == 4)
	{
		if (is_op(av[2]))
		{
			a = atoi(av[1]);
			b = atoi(av[3]);
			res = do_op(a, b, av[2][0]);
			printf("%i", res);
		}
	}
	printf("\n");
	return (0);
}
