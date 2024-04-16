/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:11:35 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/02 17:11:38 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	c;
	char	*a;
	char	*r;

	c = 0;
	a = (char *)s;
	while (*a != '\0')
	{
		c++;
		a++;
	}
	c++;
	r = malloc(c);
	if (r == NULL)
		return (r);
	a = r;
	while (*s != '\0')
	{
		*a = *s;
		a++;
		s++;
	}
	*a = *s;
	return (r);
}
