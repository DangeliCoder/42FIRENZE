/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:51:04 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/07 12:50:47 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check_start(char const *s, unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && i < start)
		i++;
	if (i == start)
		return (1);
	return (0);
}

static char	*my_malloc(char const *s, unsigned int start, size_t *len)
{
	unsigned int	i;
	char			*res;
	size_t			len2;

	len2 = 0;
	i = start;
	while (s[i] != '\0' && len2 < *len)
	{
		i++;
		len2++;
	}
	res = malloc(len2 + 1);
	*len = len2;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	if (!check_start(s, start))
	{
		res = malloc(1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	res = my_malloc(s, start, &len);
	if (res == NULL)
		return (res);
	i = 0;
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
