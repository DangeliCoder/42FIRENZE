/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:21:04 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/27 13:21:07 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static size_t	check(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	while (*big != '\0' && *little != '\0')
	{
		if (*big != *little)
			return (i);
		big++;
		little++;
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	r;

	if (*little == '\0' && len <= 0)
		return ((char *)big);
	if (len <= 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	i = ft_strlen(little);
	j = 0;
	while (*big != '\0')
	{
		r = check(big, little);
		if ((j + r) > len)
			return (NULL);
		if (r == i)
			return ((char *)big);
		big++;
		j++;
	}
	return (NULL);
}
