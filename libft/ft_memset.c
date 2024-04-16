/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:13:30 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/13 10:13:33 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*a;
	int		i;

	a = s;
	i = 0;
	while (i < (int)n)
	{
		*a = (char)c;
		a++;
		i++;
	}
	return (s);
}