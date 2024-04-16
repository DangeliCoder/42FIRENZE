/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:49:20 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/16 11:49:23 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_move(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*aux;

	if (dest == NULL && src == NULL)
		return (dest);
	if (dest < (src + n) && dest > src)
	{
		aux = malloc(n);
		ft_move(aux, src, n);
		ft_move(dest, aux, n);
		free(aux);
	}
	else
		ft_move(dest, src, n);
	return (dest);
}
