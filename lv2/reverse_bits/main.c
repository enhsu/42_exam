/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:54:44 by chsu              #+#    #+#             */
/*   Updated: 2018/12/09 14:56:11 by chsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet);

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

// Bitwise Operators in C:
// https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm
