/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:28:31 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:34 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	new_size;
	size_t	i;
	char	*res;
	char	*aux;

	new_size = size * nmemb;
	res = malloc(new_size);
	if (!res)
		return (NULL);
	aux = res;
	i = 0;
	while (i < new_size)
	{
		*aux = '\0';
		aux++;
		i++;
	}
	return ((void *)res);
}
