/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:07:33 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 17:07:36 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

void	write_address(void *addr)
{
	unsigned long long	d;
	unsigned long long	e;
	unsigned long long	c;

	d = 1;
	e = 1;
	while (e <= 7)
	{
		d *= 256;
		e++;
	}
	c = (unsigned long long)addr / d;
	write_hex(c);
	while (e > 1)
	{
		c = (unsigned long long)addr % d;
		d /= 256;
		c /= d;
		write_hex((char)c);
		e--;
	}
	c = ':';
	write(1, &c, 1);
	c = ' ';
	write(1, &c, 1);
}

void	write_hexdec(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;

	c = ' ';
	i = 0;
	while (i < 16)
	{
		if (i >= size)
		{
			write(1, &c, 1);
			write(1, &c, 1);
		}
		else
			write_hex(*(unsigned char *)(addr + i));
		if (i % 2 != 0)
			write(1, &c, 1);
		i++;
	}
}

void	write_chars(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	c;

	c = '.';
	i = 0;
	while (i < size)
	{
		if (*(char *)(addr + i) < 0x20 || *(char *)(addr + i) > 0x7E)
			write(1, &c, 1);
		else
			write(1, (char *)(addr + i), 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	c;
	unsigned int	i;

	i = 0;
	while (size > 0)
	{
		write_address(addr + i);
		if (size >= 16)
		{
			write_hexdec(addr + i, 16);
			write_chars(addr + i, 16);
		}
		else
		{
			write_hexdec(addr + i, size);
			write_chars(addr + i, size);
		}
		c = '\n';
		write(1, &c, 1);
		i += 16;
		if (size < 16)
			break ;
		size -= 16;
	}
	return (addr);
}

int	main(void)
{
	char	*str;
	char	*str2;

	str = "Ciao Antonio!";
	str2 = ft_print_memory((void *)str, 135);
	if (str2 != str)
		printf("\nERROR!\n");
	return (0);
}
(0);
}*/
