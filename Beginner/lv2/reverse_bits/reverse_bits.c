/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:40:48 by chsu              #+#    #+#             */
/*   Updated: 2018/12/09 14:57:36 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	ret;
	int				i;

	ret = 0;
	i = 0;
	while (i < 8)
	{
		// (octet & 1) get the rightest one bit
		ret = (ret << 1) | (octet & 1);
		octet = (octet >> 1);
		i++;
	}
	return (ret);
}
