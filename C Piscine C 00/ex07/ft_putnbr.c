/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:45:20 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/07 18:15:30 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	mylog10(int n)
{
	int	r;

	r = 0;
	while (n >= 10)
	{
		n /= 10;
		r++;
	}
	return (r);
}

int	mypow10(int n)
{
	int	r;

	r = 1;
	while (n > 0)
	{
		r *= 10;
		n--;
	}
	return (r);
}

void	ft_putnbr2(int nb)
{
	char	c;
	long	e;

	c = '-';
	write(1, &c, 1);
	nb = 2147483647;
	e = mylog10(nb);
	while (e > 0)
	{
		c = '0' + nb / mypow10(e);
		write(1, &c, 1);
		nb %= mypow10(e);
		e--;
	}
	c = '8';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	c;
	long	e;

	if (nb == -2147483648)
	{
		ft_putnbr2(nb);
		return ;
	}
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = -nb;
	}
	e = mylog10(nb);
	while (e >= 0)
	{
		c = '0' + nb / mypow10(e);
		write(1, &c, 1);
		nb %= mypow10(e);
		e--;
	}
}
/*
int	main(void)
{
	char	c;

	c = ' ';
	ft_putnbr(-2147483648);
	write(1, &c, 1);
	ft_putnbr(-1299938844);
	write(1, &c, 1);
	ft_putnbr(42);
	write(1, &c, 1);
	ft_putnbr(0);
	return (0);
}*/
