/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf6.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:01:05 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:58 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for writing the completament of buffer for an unsigned integer
// It returns the number of written characters.
static int	write_comp_uns(unsigned int n, size_t *buf_len, char c)
{
	int		l;
	int		l2;

	l2 = 1 + mylog10(n);
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

// Function for writing the module of an unsigned integer
// It returns the number of written characters.
static int	write_mod_uns(unsigned int n)
{
	int		e;
	int		l;
	char	c;

	e = mylog10(n);
	l = 0;
	while (e >= 0)
	{
		c = '0' + n / mypow10(e);
		write(1, &c, 1);
		l++;
		n %= mypow10(e);
		e--;
	}
	return (l);
}

// Function for writing a variable argoument of type unsigned integer.
// It returns the number of written characters.
static int	write_unsigned_integer(va_list argptr, size_t *buf_len, char *flags)
{
	unsigned int	n;
	int				l;

	n = va_arg(argptr, unsigned int);
	l = 0;
	if ((!flags[0] && !flags[1]) || (!flags[0] && flags[3]))
		l += write_comp_uns(n, buf_len, ' ');
	if (buf_len[1] == 0 && !flags[3] && !flags[0])
		buf_len[1] = buf_len[0];
	if (flags[1] || flags[3])
		l += write_comp_uns(n, buf_len, '0');
	if (n != 0 || !flags[3] || buf_len[1] > 0)
		l += write_mod_uns(n);
	else if (buf_len[0] > 0)
		l += write_chars(' ', 1);
	if (flags[0])
		l += write_comp_uns(n, buf_len, ' ');
	return (l);
}
