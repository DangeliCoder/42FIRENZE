/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:36:11 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/16 11:36:15 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

static void	ft_putnbr_fd2(int n, int fd, int p)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		n = -n;
	}
	while (p > 0)
	{
		c = '0' + n / p;
		write(fd, &c, 1);
		n %= p;
		p /= 10;
	}
}

static void	ft_putnbr_fd3(int fd)
{
	char	c;
	int		n;
	int		p;

	c = '-';
	write(fd, &c, 1);
	n = INT_MAX;
	p = 1000000000;
	while (p > 0)
	{
		if (p == 1)
			c = '8';
		else
			c = '0' + n / p;
		write(fd, &c, 1);
		n %= p;
		p /= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	a;
	int	p;

	if (n == INT_MIN)
	{
		ft_putnbr_fd3(fd);
		return ;
	}
	a = n;
	if (a <= 0)
		a = -a;
	p = 1;
	while (a >= 10)
	{
		p *= 10;
		a /= 10;
	}
	ft_putnbr_fd2(n, fd, p);
}
