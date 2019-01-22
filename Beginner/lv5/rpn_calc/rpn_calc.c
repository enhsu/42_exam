/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:56:23 by chsu              #+#    #+#             */
/*   Updated: 2018/12/09 23:35:02 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn_calc.h"

int		is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

int		is_op(char c)
{
	return (c == '+' || c == '-' || c == '*' ||
			c == '/' || c == '%');
}

int		input_valid(char *s)
{
	int	i;
	int	num;
	int	op;

	i = 0;
	num = 0;
	op = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
		{
			if (i == 0)
			{
				if (is_op(s[i]))
					return (0);
				else
					num++;
			}
			else if (!is_op(s[i]) && is_space(s[i - 1]))
				num++;
			else if (is_op(s[i]))
				op++;
		}
		i++;
	}
	if (num == op + 1)
		return (1);
	else
		return (0);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		get_number(char *s, int i, int j)
{
	int		ret;
	char	*sub;
	int		c;

	sub = (char*)malloc(sizeof(char) * (j - i + 2));
	c = 0;
	while (c < j - i + 1)
	{
		sub[c] = s[i + c];
		c++;
	}
	sub[c] = '\0';
	ret = atoi(sub);
	free(sub);
	return (ret);
}

char	*get_op_arr(char *s)
{
	char	*ret;
	int		ret_i;
	int		i;

	ret = (char*)malloc(sizeof(char) * ft_strlen(s));
	i = 0;
	ret_i = 0;
	while (s[i])
	{
		if (is_op(s[i]))
		{
			ret[ret_i] = s[i];
			ret_i++;
		}
		i++;
	}
	ret[ret_i] = '\0';
	return (ret);
}

int		get_fn_i(char *s)
{
	int	i;
	int	j;
	int	fn_i;

	i = 0;
	fn_i = 0;
	while (s[i])
	{
		j = i;
		while (s[j] && !is_space(s[j]))
			j++;
		// j is space right now
		j++;	// j is num right now
		while (s[j] && !is_space(s[j]))
			j++;
		// j is space right now, j + 1 should be op
		if (is_op(s[j + 1]))
		{
			fn_i = i;
			break ;
		}
		i++;
	}
	return (fn_i);
}

int		*get_num_arr(char *s, int *arr_l)
{
	int	*ret;
	int	i;
	int	j;
	int	fn_i;
	int	ret_i;

	ret = (int*)malloc(sizeof(int) * ft_strlen(s));
	fn_i = get_fn_i(s);
	// printf("first index: %i\n", fn_i);

	// from fn_i to the first op
	ret_i = 0;
	i = fn_i;
	while (!is_op(s[i]))
	{
		if (!is_space(s[i]) && !is_op(s[i]) && (i == 0 || is_space(s[i - 1])))
		{
			j = i;
			while (s[j] && !is_space(s[j]))
				j++;
			ret[ret_i] = get_number(s, i, j);
			(*arr_l)++;
			ret_i++;
		}
		i++;
	}
	// from fn_i to the beginning
	i = fn_i - 1;
	while (i >= 0)
	{
		if (!is_space(s[i]) && !is_op(s[i]) && (i == 0 || is_space(s[i - 1])))
		{
			j = i;
			while (s[j] && !is_space(s[j]))
				j++;
			ret[ret_i] = get_number(s, i, j);
			(*arr_l)++;
			ret_i++;
		}
		i--;
	}
	return (ret);
}

int		*get_num2_arr(char *s)
{
	int	*ret;
	int	i;
	int	j;
	int	fn_i;
	int	ret_i;

	ret = (int*)malloc(sizeof(int) * ft_strlen(s));
	fn_i = get_fn_i(s);
	ret_i = 0;
	// from fn_i to the end
	i = fn_i + 1;
	while (s[i] && !is_space(s[i]))
		i++;
	// s[i] should be white space
	i++;
	// s[i] should be number
	while (s[i] && !is_space(s[i]))
		i++;
	// s[i] should be white space
	while (s[i])
	{
		if (!is_space(s[i]) && !is_op(s[i]) && (i == 0 || is_space(s[i - 1])))
		{
			j = i;
			while (s[j] && !is_space(s[j]))
				j++;
			ret[ret_i] = get_number(s, i, j);
			ret_i++;
		}
		i++;
	}
	return (ret);
}

int		do_op(int num1, int num2, char op)
{
	int	ret;

	ret = 0;
	if (op == '+')
		ret = num1 + num2;
	else if (op == '-')
		ret = num1 - num2;
	else if (op == '*')
		ret = num1 * num2;
	else if (op == '/')
		ret = num1 / num2;
	else if (op == '%')
		ret = num1 % num2;
	return (ret);
}

void	rpn_calc(char *s)
{
	char	*op;
	int		*num;
	int		num_l;
	int		*num2;
	int		op_i;
	int		num_i;
	int		num2_i;
	int		result;

	if (!input_valid(s))
	{
		printf("Error");
		return ;
	}
	num_l = 0;
	op = get_op_arr(s);
	num = get_num_arr(s, &num_l);
	num2 = get_num2_arr(s);
	
	op_i = 0;
	num_i = 0;
	num2_i = 0;
	result = 0;
	while (op[op_i])
	{
		if (num_i < num_l)
		{
			if (num_i == 0)
			{
				result = do_op(num[num_i], num[num_i + 1], op[op_i]);
				num_i += 2;
			}
			else
			{
				result = do_op(num[num_i], result, op[op_i]);
				num_i++;
			}
		}
		else
		{
			result = do_op(result, num2[num2_i], op[op_i]);
			num2_i++;
		}
		op_i++;
	}
	printf("%i", result);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rpn_calc(av[1]);
	else
		printf("Error");
	printf("\n");
	return (0);
}
