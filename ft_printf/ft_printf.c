/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:55:37 by ad-angel          #+#    #+#             */
/*   Updated: 2023/12/04 12:55:40 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function for writing a part of the string format.
// It returns the number of written characters.
static int	write_format(const char **format, int l)
{
	write(1, *format, l);
	(*format) += l;
	return (l);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		l;

	if (format == NULL)
		return (-1);
	va_start(argptr, format);
	l = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			l += operations(&format, argptr);
		else
			l += write_format(&format, 1);
	}
	va_end(argptr);
	return (l);
}
