/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf5.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:45:20 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:50 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for writing the completament of buffer for an integer
// It returns the number of written characters.
static int	write_comp(int n, size_t *buf_len, char c, char int_min)
{
	int		l;
	int		l2;

	if (n < 0)
		l2 = 2 + mylog10(-n);
	else
		l2 = 1 + mylog10(n);
	if (int_min)
		l2++;
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

// Function for writing the module of integer
// It returns the number of written characters.
static int	write_mod(int n, char int_min)
{
	int		e;
	int		l;
	char	c;

	if (n < 0)
		n = -n;
	e = mylog10(n);
	l = 0;
	while (e >= 0)
	{
		c = '0' + n / mypow10(e);
		write(1, &c, 1);
		l++;
		n %= mypow10(e);
		e--;
		if (int_min && e == 0)
			break ;
	}
	if (int_min)
	{
		c = '8';
		write(1, &c, 1);
		l++;
	}
	return (l);
}

// Function for writing the sign of integer or a space.
// It returns the number of written characters.
static int	write_sign(int n, char *flags)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(1, &c, 1);
		return (1);
	}
	if (flags[4])
	{
		c = ' ';
		write(1, &c, 1);
		return (1);
	}
	if (flags[5])
	{
		c = '+';
		write(1, &c, 1);
		return (1);
	}
	return (0);
}

// Function for writing the minimum value of an integer.
// It returns the number of written characters.
static int	write_min_int(size_t *buf_len, char *flags)
{
	int		l;

	l = 0;
	if ((!flags[0] && !flags[1]) || (!flags[0] && flags[3]))
		l += write_comp(INT_MAX, buf_len, ' ', 1);
	l += write_sign(INT_MIN, flags);
	if (buf_len[1] == 0 && !flags[3] && !flags[0])
		buf_len[1] = buf_len[0];
	if (flags[1] || flags[3])
		l += write_comp(INT_MAX, buf_len, '0', 1);
	l += write_mod(INT_MAX, 1);
	if (flags[0])
		l += write_comp(INT_MAX, buf_len, ' ', 1);
	return (l);
}

// Function for writing a variable argoument of type integer.
// It returns the number of written characters.
static int	write_integer(va_list argptr, size_t *buf_len, char *flags)
{
	int	n;
	int	l;

	n = va_arg(argptr, int);
	if (n < 0 && flags[3])
		buf_len[1]++;
	if (n == INT_MIN)
		return (write_min_int(buf_len, flags));
	l = 0;
	if ((!flags[0] && !flags[1]) || (!flags[0] && flags[3]))
		l += write_comp(n, buf_len, ' ', 0);
	l += write_sign(n, flags);
	if (buf_len[1] == 0 && !flags[3] && !flags[0])
		buf_len[1] = buf_len[0];
	if (flags[1] || flags[3])
		l += write_comp(n, buf_len, '0', 0);
	if (n != 0 || !flags[3] || buf_len[1] > 0)
		l += write_mod(n, 0);
	else if (buf_len[0] > 0)
		l += write_chars(' ', 1);
	if (flags[0])
		l += write_comp(n, buf_len, ' ', 0);
	return (l);
}
