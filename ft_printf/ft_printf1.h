/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:45:19 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/03 11:05:54 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for the calculation of a power of 10.
static unsigned long long	mypow10(unsigned int n)
{
	unsigned long long	r;

	r = 1;
	while (n > 0)
	{
		r *= 10;
		n--;
	}
	return (r);
}

// Function for the calculation of a logarithm with base equal to 10.
static unsigned int	mylog10(unsigned long long n)
{
	unsigned int	r;

	r = 0;
	while (n >= 10)
	{
		n /= 10;
		r++;
	}
	return (r);
}

// Function for the calculation of a power of 16.
static unsigned long long	mypow16(unsigned int n)
{
	unsigned long long	r;

	r = 1;
	while (n > 0)
	{
		r *= 16;
		n--;
	}
	return (r);
}

// Function for the calculation of a logarithm with base equal to 16.
static unsigned int	mylog16(unsigned long long n)
{
	unsigned int	r;

	r = 0;
	while (n >= 16)
	{
		n /= 16;
		r++;
	}
	return (r);
}

// Function for writing a hexdecimal digit.
// It returns the number of written characters.
static int	write_hex(unsigned char n, int lower)
{
	char	c;

	if (n < 10)
		c = '0' + n;
	else
	{
		if (lower)
			c = 'a' + (n - 10);
		else
			c = 'A' + (n - 10);
	}
	write(1, &c, 1);
	return (1);
}
