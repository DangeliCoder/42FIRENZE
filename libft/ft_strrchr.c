/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:47:13 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/26 12:47:23 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	c %= 256;
	res = (char *)s;
	while (*res != '\0')
		res++;
	while (*res != c && res != s)
		res--;
	if (*res != c)
		return (NULL);
	return (res);
}
