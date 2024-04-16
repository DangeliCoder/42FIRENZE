/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:46:36 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:41 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for writing the completament of buffer for a pointer to
// "void" value in hexadecimal format.
// It returns the number of written characters.
static int	write_comp_void_ptr(unsigned long long addr, size_t *buf_len,
								char c, char space)
{
	int		l;
	int		l2;

	l2 = 3 + mylog16(addr);
	if (buf_len[0] > 0 && space)
		l2++;
	l = 0;
	while (buf_len[0] > (size_t)l2)
	{
		write(1, &c, 1);
		l++;
		buf_len[0]--;
	}
	return (l);
}

// Function for writing the prefix of an address of memory.
// It returns the number of written characters.
static int	write_prefix(size_t *buf_len, char space)
{
	char	c;
	int		l;

	l = 0;
	if (buf_len[0] > 0 && space)
	{
		c = ' ';
		write(1, &c, 1);
		l++;
	}
	c = '0';
	write(1, &c, 1);
	c = 'x';
	write(1, &c, 1);
	l += 2;
	return (l);
}

// Function for writing an address of memory.
// It returns the number of written characters.
static int	write_address(unsigned long long addr)
{
	unsigned long long	d;
	unsigned long long	c;
	int					l;
	unsigned char		start;

	d = mypow16(mylog16(addr));
	l = 0;
	start = 0;
	c = addr / d;
	while (1)
	{
		if (!start && c > 0)
			start = 1;
		if (start)
			l += write_hex((unsigned char)c, 1);
		c = addr % d;
		d /= 16;
		if (d == 0)
			break ;
		c /= d;
	}
	return (l);
}

// Function for writing the value of a pointer to
// "void" value in hexadecimal format when it is equal to NULL.
// It returns the number of written characters.
static int	write_void_ptr_null(size_t *buf_len, char *flags)
{
	char	*s;
	int		l;

	l = 0;
	s = "(nil)";
	if (!flags[0])
		l += write_comp_str(s, buf_len, flags);
	write(1, s, 5);
	l += 5;
	if (flags[0])
		l += write_comp_str(s, buf_len, flags);
	return (l);
}

// Function for writing the value of a pointer to
// "void" value in hexadecimal format.
// It returns the number of written characters.
static int	write_void_ptr(va_list argptr, size_t *buf_len, char *flags)
{
	void	*ptr;
	int		l;

	ptr = va_arg(argptr, void *);
	if (ptr == NULL)
		return (write_void_ptr_null(buf_len, flags));
	l = 0;
	if (!flags[0] && !flags[1])
		l += write_comp_void_ptr((unsigned long long)ptr, buf_len,
				' ', flags[4]);
	l += write_prefix(buf_len, flags[4]);
	if (!flags[0] && flags[1])
		l += write_comp_void_ptr((unsigned long long)ptr, buf_len,
				'0', flags[4]);
	l += write_address((unsigned long long)ptr);
	if (flags[0])
		l += write_comp_void_ptr((unsigned long long)ptr, buf_len,
				' ', flags[4]);
	return (l);
}
