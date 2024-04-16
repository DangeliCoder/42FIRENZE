/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:10:14 by ad-angel          #+#    #+#             */
/*   Updated: 2023/10/13 12:10:17 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	int		i;

	a = s;
	i = 0;
	while (i < (int)n)
	{
		*a = '\0';
		a++;
		i++;
	}
}