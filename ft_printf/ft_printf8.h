/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf8.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:23:01 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:09:31 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for writing a variable argoument of
// type unsigned integer in hexdecimal format (lowercase).
// It returns the number of written characters.
static int	write_per_cent(void)
{
	char	c;

	c = '%';
	write(1, &c, 1);
	return (1);
}

// Function for the conversions of the argouments
// It returns the number of written characters.
static int	conversions(char *flags, size_t *buf_len, char c, va_list argptr)
{
	int	l;

	if (c == 'c')
		l = write_char(argptr, buf_len, flags);
	else if (c == 's')
		l = write_str(argptr, buf_len, flags);
	else if (c == 'p')
		l = write_void_ptr(argptr, buf_len, flags);
	else if (c == 'i' || c == 'd')
		l = write_integer(argptr, buf_len, flags);
	else if (c == 'u')
		l = write_unsigned_integer(argptr, buf_len, flags);
	else if (c == 'x')
		l = write_integer_hex_low(argptr, buf_len, flags);
	else if (c == 'X')
		l = write_integer_hex_high(argptr, buf_len, flags);
	else if (c == '%')
		l = write_per_cent();
	else
		l = -1;
	return (l);
}

// Function for the initialization of the array of flags
// flags[0] <-> '-'
// flags[1] <-> '0'
// flags[2] <-> '#'
// flags[3] <-> '.'
// flags[4] <-> ' '
// flags[5] <-> '+'
static void	init_flags(const char **ptr, char *flags)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		flags[i] = 0;
		i++;
	}
	while (**ptr == '-' || **ptr == '0' || **ptr == '#'
		|| **ptr == ' ' || **ptr == '+')
	{
		if (**ptr == '-')
			flags[0] = 1;
		if (**ptr == '0')
			flags[1] = 1;
		if (**ptr == '#')
			flags[2] = 1;
		if (**ptr == ' ')
			flags[4] = 1;
		if (**ptr == '+')
			flags[5] = 1;
		(*ptr)++;
	}
}

// Function for the initialization of the buffer's length
// It returns the the buffer's length.
static void	init_buf_len(const char **ptr, size_t *buf_len, char *flags)
{
	buf_len[0] = atoi(*ptr);
	while ((**ptr >= '0' && **ptr <= '9'))
		(*ptr)++;
	if (**ptr == '.')
	{
		flags[3] = 1;
		(*ptr)++;
	}
	if (**ptr == '0')
	{
		flags[1] = 1;
		(*ptr)++;
	}
	buf_len[1] = atoi(*ptr);
	while ((**ptr >= '0' && **ptr <= '9'))
		(*ptr)++;
}

// Function for reading the string format
// It returns the number of written characters.
static int	operations(const char **ptr, va_list argptr)
{
	char		flags[6];
	const char	*ptr2;
	size_t		buf_len[2];
	int			l;

	ptr2 = *ptr;
	(*ptr)++;
	init_flags(ptr, flags);
	if (**ptr == '\0')
		return (0);
	init_buf_len(ptr, buf_len, flags);
	if (**ptr == '\0')
		return (0);
	l = conversions(flags, buf_len, **ptr, argptr);
	if (l == -1)
	{
		*ptr = ptr2;
		write_per_cent();
		l = 1;
	}
	(*ptr)++;
	return (l);
}
