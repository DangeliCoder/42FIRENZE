/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:44:33 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/27 12:44:37 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
