/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:48:56 by chsu              #+#    #+#             */
/*   Updated: 2018/12/10 23:49:02 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ten(int i)
{
	int	ret = 1;

	while (i > 1)
	{
		ret *= 10;
		i--;
	}
	return (ret);
}

char	*ft_itoa(int nbr)
{
	char	*ret;
	int		tmp;
	int		n_l;
	int		pon;
	int		i;

	n_l = 1;
	pon = 1;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ret = (char*)malloc(sizeof(char) * 12);
			ret[0] = '-';
			ret[1] = '2';
			ret[2] = '1';
			ret[3] = '4';
			ret[4] = '7';
			ret[5] = '4';
			ret[6] = '8';
			ret[7] = '3';
			ret[8] = '6';
			ret[9] = '4';
			ret[10] = '8';
			ret[11] = '\0';
			return (ret);
		}
		else
		{
			pon = -1;
			nbr *= -1;
		}
	}
	tmp = nbr;
	while (tmp / 10 > 0)
	{
		tmp /= 10;
		n_l++;
	}
	if (pon == 1)
		ret = (char*)malloc(sizeof(char) * (n_l + 1));
	else
		ret = (char*)malloc(sizeof(char) * (n_l + 2));
	i = 0;
	if (pon == -1)
	{
		ret[0] = '-';
		i++;
	}
	while (nbr / 10 > 0)
	{
		ret[i] = (nbr / ft_ten(n_l)) + '0';
		nbr -= ft_ten(n_l) * (nbr / ft_ten(n_l));
		n_l--;
		i++;
	}
	ret[i] = nbr + '0';
	ret[i + 1] = '\0';
	return (ret);
}
