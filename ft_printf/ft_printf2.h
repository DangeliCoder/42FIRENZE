/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:03 by ad-angel          #+#    #+#             */
/*   Updated: 2024/01/23 17:08:11 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function for calculating the length of a string.
// It returns the length calculated.
static size_t	string_len(char *s)
{
	size_t	l;

	l = 0;
	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

// Function for writing a sequence of n characters
// equal to c.
// It returns the number of written characters.
static int	write_chars(char c, size_t n)
{
	int	l;

	l = 0;
	while (n > 0)
	{
		write(1, &c, 1);
		l++;
		n--;
	}
	return (l);
}
