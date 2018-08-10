/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 13:18:55 by chsu              #+#    #+#             */
/*   Updated: 2018/08/10 13:41:20 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	is_char(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ret;
	int	pon;

	i = 0;
	ret = 0;
	pon = 1;
	while (!is_nbr(str[i]) && str[i] != '-')
	{
		if (is_char(is_char(str[i])))
			return (0);
		i++;
	}
	if (str[i] == '-')
	{
		pon *= -1;
		i++;
	}
	while (is_nbr(str[i]))
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return (ret * pon);
}

// for testing

void	test(char *s)
{
	printf("atoi : %i\n", atoi(s));
	printf("ft_atoi : %i\n", ft_atoi(s));
}

int	main(void)
{
	test("-123");
	test("-42abc");
	test("abc123");
	test("434sdf5326");
}
