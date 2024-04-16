/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:22:07 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/08 12:41:30 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_comb[10];
char	g_start;

void	write_comb(int n, int s)
{
	char	c;
	char	i;

	g_comb[n - 1] = '0' + s;
	while (g_comb[n - 1] <= '9')
	{
		if (g_start != 1)
		{
			c = ',';
			write(1, &c, 1);
			c = ' ';
			write(1, &c, 1);
		}
		g_start = 0;
		i = 0;
		while (i < n)
		{
			write(1, &g_comb[(int)i], 1);
			i++;
		}
		g_comb[n - 1]++;
	}
}

void	fun(int n, int i, int s)
{
	char	j;

	if (i == (n - 1))
	{
		write_comb(n, s);
		return ;
	}
	g_comb[i] = '0' + s;
	j = s;
	while (g_comb[i] <= '9')
	{
		fun(n, i + 1, j + 1);
		g_comb[i]++;
		j++;
	}
}

void	ft_print_combn(int n)
{
	g_start = 1;
	fun(n, 0, 0);
}
/*
int	main(void)
{
	int	n;

	n = 9;
	ft_print_combn(n);
	return (0);
}*/
