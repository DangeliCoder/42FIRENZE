/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:38:03 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/13 12:38:06 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	len_calc(char const *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	char		*res;

	if (f == NULL)
		return (NULL);
	len = len_calc(s);
	res = (char *)malloc(len);
	if (res == NULL)
		return (NULL);
	len--;
	res[len] = '\0';
	if (len == 0)
		return (res);
	len--;
	while (len > 0)
	{
		res[len] = f(len, s[len]);
		len--;
	}
	res[len] = f(len, s[len]);
	return (res);
}
