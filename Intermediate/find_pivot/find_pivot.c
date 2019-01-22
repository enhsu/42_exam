/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 23:38:37 by chsu              #+#    #+#             */
/*   Updated: 2019/01/21 23:48:33 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_pivot(int *arr, int n)
{
	int	total = 0;
	int	left = 0;
	
	for (int i = 0; i < n; i++)
	{
		total += arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (left == total - left - arr[i])
			return i;
		left += arr[i];
	}
	return -1;
}
