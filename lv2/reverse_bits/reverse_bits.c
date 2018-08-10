/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 14:53:25 by chsu              #+#    #+#             */
/*   Updated: 2018/08/10 15:00:55 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>						// for testing

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	c;
	unsigned int	i;

	c = 0;
	i = 8;
	while (i--)
	{
		c = (c << 1) | (octet & 1);		// (octet & 1) get the rightest one bit
		octet = (octet >> 1);
	}
	return (c);
}

// for testing
int				main(void)
{
	unsigned char c;

	// expected: '&' -reverse-> 'd'
	c = '&';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
