/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:23:59 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/13 15:24:02 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const void	*aux1;
	const void	*aux2;
	size_t		c;

	aux1 = src;
	aux2 = dest;
	c = 0;
	while (src != aux2 && dest != aux1 && c < n)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		c++;
	}
	if (c == n)
		return ((void *)aux2);
	return (NULL);
}
