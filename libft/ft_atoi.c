/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:52:19 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/30 16:52:25 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_atoi2(const char *nptr, int sign)
{
	int	res;

	res = 0;
	while (*nptr != '\0')
	{
		if (*nptr < '0' || *nptr > '9')
			break ;
		res *= 10;
		res += (*nptr - '0');
		nptr++;
	}
	res *= sign;
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int	sign;

	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == ' ')
		nptr++;
	if ((*nptr < '0' || *nptr > '9') && *nptr != '+' && *nptr != '-')
		return (0);
	if (*nptr == '+')
	{
		nptr++;
		if (*nptr < '0' || *nptr > '9')
			return (0);
	}
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	return (ft_atoi2(nptr, sign));
}
