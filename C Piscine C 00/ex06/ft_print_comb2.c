/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:14:41 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/07 17:14:54 by ad-angel         ###   ########.fr       */
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

void	write_comb(int n1, int n2)
{
	char	c;

	c = '0' + n1 / 10;
	write(1, &c, 1);
	c = '0' + n1 % 10;
	write(1, &c, 1);
	c = ' ';
	write(1, &c, 1);
	c = '0' + n2 / 10;
	write(1, &c, 1);
	c = '0' + n2 % 10;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	n1;
	int	n2;
	int	start;

	start = 1;
	n1 = 0;
	while (n1 <= 99)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			if (!start)
				write_sep();
			start = 0;
			write_comb(n1, n2);
			n2++;
		}
		n1++;
	}
}
/*
int main()
{
	ft_print_comb2();
	return 0;
}*/
