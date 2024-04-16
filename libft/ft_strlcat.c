/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:56:11 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/16 17:56:15 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* This is for a conceptual error!
	if (i > size)
		i = size;*/
static size_t	count_overflow(char *dst, const char *src, size_t size,
				size_t i)
{
	while (*dst != '\0')
	{
		i++;
		dst++;
	}
	if (i > size)
		i = size;
	while (*src != '\0')
	{
		i++;
		src++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (*dst != '\0' && i < size)
		{
			i++;
			dst++;
		}
		while (*src != '\0' && i < (size - 1))
		{
			*dst = *src;
			dst++;
			src++;
			i++;
		}
		if (i < size)
			*dst = '\0';
	}
	return (count_overflow(dst, src, size, i));
}
