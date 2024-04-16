/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:45:19 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:25 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for writing the completament of buffer for a char
// It returns the number of written characters.
static int	write_comp_char(size_t *buf_len)
{
	int		l2;
	char	c;

	if (buf_len[0] == 0)
		return (0);
	buf_len[0]--;
	l2 = (int)buf_len[0];
	c = ' ';
	while (buf_len[0] > 0)
	{
		write(1, &c, 1);
		buf_len[0]--;
	}
	return (l2);
}

// Function for writing a variable argoument of type "char".
// It returns the number of written characters.
static int	write_char(va_list argptr, size_t *buf_len, char *flags)
{
	char	c;
	int		l;

	c = va_arg(argptr, int);
	l = 0;
	if (!flags[0])
		l += write_comp_char(buf_len);
	write(1, &c, 1);
	l++;
	if (flags[0])
		l += write_comp_char(buf_len);
	return (l);
}

// Function for writing the completament of buffer for a string
// It returns the number of written characters.
static int	write_comp_str(char *s, size_t *buf_len, char *flags)
{
	int		l;
	int		l2;
	char	c;

	if (!flags[3])
		buf_len[1] = string_len(s);
	c = ' ';
	l = 0;
	l2 = (int)buf_len[0];
	while (l2 > (int)buf_len[1])
	{
		write(1, &c, 1);
		l++;
		l2--;
	}
	while (l2 > (int)string_len(s))
	{
		write(1, &c, 1);
		l++;
		l2--;
	}
	return (l);
}

// Function for writing the visible part of a string.
// It returns the number of written characters.
static int	write_str_vis(char *s, size_t *buf_len, char *flags)
{
	if (flags[3] && string_len(s) > buf_len[1])
		return (write(1, s, buf_len[1]));
	return (write(1, s, string_len(s)));
}

// Function for writing a variable argoument of type "char *".
// It returns the number of written characters.
static int	write_str(va_list argptr, size_t *buf_len, char *flags)
{
	char	*s;
	int		l;

	s = va_arg(argptr, char *);
	if (s == NULL)
	{
		if (flags[3] && buf_len[1] <= 4)
			s = "";
		else
			s = "(null)";
	}
	l = 0;
	if (!flags[0])
		l += write_comp_str(s, buf_len, flags);
	l += write_str_vis(s, buf_len, flags);
	if (flags[0])
		l += write_comp_str(s, buf_len, flags);
	return (l);
}
