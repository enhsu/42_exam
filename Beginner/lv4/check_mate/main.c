/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:20:00 by exam              #+#    #+#             */
/*   Updated: 2018/11/27 11:23:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	p_res(int i)
{
	if (i == 1)
		write(1, "Success", 7);
	else if (i == 0)
		write(1, "Fail", 4);
	else
		write(1, "ERROR", 5);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *s)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		is_piece(char c)
{
	return (c == 'P' || c == 'B' || c == 'R' || c == 'Q');
}

int		check_p(char **arr, int i, int j)
{
	if (i > 0)
	{
		if (j > 0 && j < ft_strlen(arr[i]) - 1)
		{
			if (arr[i - 1][j - 1] == 'K' || arr[i - 1][j + 1] == 'K')
				return (1);
		}
		else if (j == 0)
		{
			if (arr[i - 1][j + 1] == 'K')
				return (1);
		}
		else if (j == ft_strlen(arr[i]) - 1)
		{
			if (arr[i - 1][j - 1] == 'K')
				return (1);
		}
	}
	return (0);
}

int     check_b(char **arr, int i, int j)
{
	int	max = ft_strlen(arr[i]);
	int	min = 0;
	int	a = i - 1;
	int	b = j - 1;
	// left top
	while (a >= min && b >= min)
	{
		if (is_piece(arr[a][b]))
			break ;
		if (arr[a][b] == 'K')
			return (1);
		a--;
		b--;
	}
	// left bot
	a = i + 1;
	b = j - 1;
	while (a < max && b >= min)
	{
		if (is_piece(arr[a][b]))
			break ;
		if (arr[a][b] == 'K')
			return (1);
		a++;
		b--;
	}
	// right top
	a = i - 1;
	b = j + 1;
	while (a >= min && b < max)
	{
		if (is_piece(arr[a][b]))
            break ;
        if (arr[a][b] == 'K')
            return (1);
		a--;
		b++;
	}
	// right bot
	a = i + 1;
	b = j + 1;
	while (a < max && b < max)
	{
		if (is_piece(arr[a][b]))
            break ;
        if (arr[a][b] == 'K')
            return (1);
		a++;
		b++;
	}
	return (0);
}

int     check_r(char **arr, int i, int j)
{
	int	max = ft_strlen(arr[i]);
	int	min = 0;
	int	a = i;
	int	b = j - 1;
	// left
	while (b >= min)
	{
		if (is_piece(arr[a][b]))
            break ;
        if (arr[a][b] == 'K')
            return (1);
		b--;
	}
	// top
	a = i - 1;
	b = j;
	while (a >= min)
	{
		if (is_piece(arr[a][b]))
            break ;
        if (arr[a][b] == 'K')
            return (1);
		a--;
	}
	// right
	a = i;
	b = j + 1;
	while (b < max)
	{
		if (is_piece(arr[a][b]))
            break ;
        if (arr[a][b] == 'K')
            return (1);
		b++;
	}
	// bot
	a = i + 1;
	b = j;
	while (a < max)
	{
		if (is_piece(arr[a][b]))
            break ;
        if (arr[a][b] == 'K')
            return (1);
		a++;
	}
	return (0);
}

int     check_q(char **arr, int i, int j)
{
	return (check_b(arr, i, j) || check_r(arr, i, j));
}

int		do_check_mate(char **arr, int i, int j)
{
	int		is_check = 0;
	char	piece = arr[i][j];

	if (piece == 'P')
		is_check = check_p(arr, i, j);
	else if (piece == 'B')
		is_check = check_b(arr, i, j);
	else if (piece == 'R')
		is_check = check_r(arr, i, j);
	else
		is_check = check_q(arr, i, j);
	if (is_check)
		return (1); // p_res(1);
	else
		return (0); // p_res(0);
}

void	check_SF(char **arr)
{
	int	i;
	int	j;
	int	is_check = 0;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (is_piece(arr[i][j]))
				is_check = do_check_mate(arr, i, j);
			j++;
		}
		i++;
	}
	if (is_check)
		p_res(1);
	else
		p_res(0);
}

void	save_input(int ac, char **av)
{
	char	**arr;
	int		i;

	arr = (char**)malloc(sizeof(char*) * ac);
	/* error check
	if (!arr)
		p_res(-1);
	*/
	i = 0;
	while (i < ac - 1)
	{
		/* error check
		if (ft_strlen(av[i]) != ac - 1)
			p_res(-1);
		*/
		arr[i] = ft_strcpy(av[i + 1]);
		i++;
	}
	arr[i] = NULL;
	check_SF(arr);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		save_input(ac, av);
	write(1, "\n", 1);
	return (0);
}
