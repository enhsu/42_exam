/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:23:47 by chsu              #+#    #+#             */
/*   Updated: 2019/01/28 18:39:31 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_two(int i)
{
	if (i % 10 == 2)
	{
		if (i / 10 > 0)
			return (1 + check_two(i / 10));
		else
			return (1);
	}
	if (i / 10 > 0)
		return (check_two(i / 10));
	return (0);
}

int	count_of_2(int n)
{
	int	i = 0;
	int	cr = 0;
	int	ret = 0;

	while (i <= n)
	{
		cr = check_two(i);
		if (cr)
			ret += cr;
		i++;
	}
	return (ret);
}
