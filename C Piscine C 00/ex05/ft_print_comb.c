/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:24:58 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/07 16:38:59 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_sep(void)
{
	char	c;

	c = ',';
	write(1, &c, 1);
	c = ' ';
	write(1, &c, 1);
}

void	write_comb(char c1, char c2, char c3)
{
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, &c3, 1);
}

void	ft_print_comb(void)
{
	char	c1;
	char	c2;
	char	c3;
	char	start;

	start = 1;
	c1 = '0';
	while (c1 <= '9')
	{
		c2 = c1 + 1;
		while (c2 <= '9')
		{
			c3 = c2 + 1;
			while (c3 <= '9')
			{
				if (!start)
					write_sep();
				start = 0;
				write_comb(c1, c2, c3);
				c3++;
			}
			c2++;
		}
		c1++;
	}
}
/*
int main()
{
	ft_print_comb();
	return 0;
}*/
