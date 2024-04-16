/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:10:35 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/13 10:10:41 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

static char	*ft_itoa2(int n, size_t len)
{
	char	*res;

	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	len--;
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len] = '0' + n % 10;
		len--;
		n /= 10;
	}
	return (res);
}

static char	*ft_itoa3(void)
{
	size_t	len;
	int		n;
	char	*res;

	len = 12;
	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	res[0] = '-';
	len--;
	res[len] = '\0';
	len--;
	n = INT_MAX;
	while (n > 0)
	{
		if (len == 10)
			res[len] = '8';
		else
			res[len] = '0' + n % 10;
		len--;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		a;

	if (n == INT_MIN)
		return (ft_itoa3());
	a = n;
	if (a <= 0)
	{
		len = 1;
		a = -a;
	}
	else
		len = 0;
	while (a > 0)
	{
		len++;
		a /= 10;
	}
	len++;
	return (ft_itoa2(n, len));
}
