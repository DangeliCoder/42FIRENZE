/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:38:17 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 16:38:19 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_hex(unsigned char n)
{
	char	d;
	char	c;

	d = n / 16;
	if (d < 10)
		c = '0' + d;
	else
		c = 'a' + (d - 10);
	write(1, &c, 1);
	d = n % 16;
	if (d < 10)
		c = '0' + d;
	else
		c = 'a' + (d - 10);
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	c;

	while (*str != '\0')
	{
		if (*str < 0x20 || *str > 0x7E)
		{
			c = '\\';
			write(1, &c, 1);
			c = *str;
			write_hex(c);
		}
		else
			write(1, str, 1);
		str++;
	}
}
/*
int	main(void)
{
	char	*str;

	str = "\tCoucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	return (0);
}*/
