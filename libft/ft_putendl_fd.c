/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:40:19 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/14 17:40:21 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static size_t	len_str(char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	len++;
	return (len);
}

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	char	*a;
	char	*a2;

	if (s == NULL)
		return ;
	len = len_str(s);
	a = malloc(len);
	if (a == NULL)
		return ;
	a2 = a;
	while (*s != '\0')
	{
		*a = *s;
		a++;
		s++;
	}
	*a = '\n';
	write(fd, a2, len);
	free(a2);
}
