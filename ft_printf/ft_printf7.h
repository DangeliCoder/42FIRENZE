/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf7.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:22:20 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:09:08 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for writing the completament of buffer for a variable argoument of
// type unsigned integer in hexdecimal format.
// It returns the number of written characters.
static int	write_comp_integer_hex(unsigned int n, size_t *buf_len, char c,
									char prefix)
{
	int		l;
	int		l2;

	l2 = 1 + mylog16(n);
	if (prefix)
		l2 += 2;
	l = 0;
	if (c == '0')
	{
		if (buf_len[1] > (size_t)l2)
			l += write_chars(c, buf_len[1] - (size_t)l2);
	}
	else
	{
		if (buf_len[1] > (size_t)l2)
			l2 = (int)buf_len[1];
		if (buf_len[0] > (size_t)l2)
			l += write_chars(c, buf_len[0] - (size_t)l2);
	}
	return (l);
}

// Function for writing the prefix of a variable argoument of
// type unsigned integer in hexdecimal format.
// It returns the number of written characters.
static int	write_prefix_hex(int lower)
{
	char	c;

	c = '0';
	write(1, &c, 1);
	if (lower)
		c = 'x';
	else
		c = 'X';
	write(1, &c, 1);
	return (2);
}

// Function for writing the visible part of a variable argoument of
// type unsigned integer in hexdecimal format.
// It returns the number of written characters.
static int	write_integer_hex(unsigned int n, int lower, char prefix)
{
	int		l;
	int		e;

	if (prefix)
		l = write_prefix_hex(lower);
	else
		l = 0;
	e = mylog16(n);
	while (e >= 0)
	{
		write_hex((unsigned char)(n / mypow16(e)), lower);
		l++;
		n %= mypow16(e);
		e--;
	}
	return (l);
}

// Function for writing a variable argoument of
// type unsigned integer in hexdecimal format (lowercase).
// It returns the number of written characters.
static int	write_integer_hex_low(va_list argptr, size_t *buf_len,
									char *flags)
{
	unsigned int	n;
	char			prefix;
	int				l;

	n = va_arg(argptr, unsigned int);
	prefix = 0;
	if (flags[2] && n > 0)
		prefix = 1;
	l = 0;
	if ((!flags[0] && !flags[1]) || (!flags[0] && flags[3]))
		l += write_comp_integer_hex(n, buf_len, ' ', prefix);
	if (buf_len[1] == 0 && !flags[3] && !flags[0])
		buf_len[1] = buf_len[0];
	if (flags[1] || flags[3])
		l += write_comp_integer_hex(n, buf_len, '0', prefix);
	if (n != 0 || !flags[3] || buf_len[1] > 0)
		l += write_integer_hex(n, 1, prefix);
	else if (buf_len[0] > 0)
		l += write_chars(' ', 1);
	if (flags[0])
		l += write_comp_integer_hex(n, buf_len, ' ', prefix);
	return (l);
}

// Function for writing a variable argoument of
// type unsigned integer in hexdecimal format (lowercase).
// It returns the number of written characters.
static int	write_integer_hex_high(va_list argptr, size_t *buf_len,
									char *flags)
{
	unsigned int	n;
	char			prefix;
	int				l;

	n = va_arg(argptr, unsigned int);
	prefix = 0;
	if (flags[2] && n > 0)
		prefix = 1;
	l = 0;
	if ((!flags[0] && !flags[1]) || (!flags[0] && flags[3]))
		l += write_comp_integer_hex(n, buf_len, ' ', prefix);
	if (buf_len[1] == 0 && !flags[3] && !flags[0])
		buf_len[1] = buf_len[0];
	if (flags[1] || flags[3])
		l += write_comp_integer_hex(n, buf_len, '0', prefix);
	if (n != 0 || !flags[3] || buf_len[1] > 0)
		l += write_integer_hex(n, 0, prefix);
	else if (buf_len[0] > 0)
		l += write_chars(' ', 1);
	if (flags[0])
		l += write_comp_integer_hex(n, buf_len, ' ', prefix);
	return (l);
}
