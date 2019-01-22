/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:15:46 by chsu              #+#    #+#             */
/*   Updated: 2018/12/10 11:18:35 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	wdmatch(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[j])
	{
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write(1, s1, ft_strlen(s1));
}

int		main(int ac, char **av)
{
	if (ac == 3)
		wdmatch(av[1], av[2]);
	write(1, "\n", 1);
	return (0);
}
