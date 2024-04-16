/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:44:21 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/09 10:44:27 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

static size_t	num_chunks(char const *s, char c)
{
	size_t	num;

	if (s == NULL)
		return (0);
	if (*s == '\0')
		return (1);
	s++;
	num = 0;
	while (*s != '\0')
	{
		if (*s == c && *(s - 1) != c)
			num++;
		s++;
	}
	if (*(s - 1) != c)
		num++;
	num++;
	return (num);
}

static size_t	len_chunk(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		if (*s == c)
			break ;
		len++;
		s++;
	}
	len++;
	return (len);
}

static char	*copy_chunk(char **res, size_t i, size_t len, char const *s)
{
	char	*aux;

	res[i] = (char *)malloc(len * sizeof(char));
	if (res[i] != NULL)
		aux = ft_memcpy(res[i], s, len - 1);
	else
		aux = NULL;
	if (aux == NULL)
	{
		if (i > 0)
		{
			i--;
			while (i > 0)
			{
				free(res[i]);
				i--;
			}
			free(res[0]);
		}
		free(res);
		return (NULL);
	}
	else
		res[i][len - 1] = '\0';
	return (res[i]);
}

static char	**ft_split2(char **res, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		len = len_chunk(s, c);
		if (len > 1)
		{
			if (copy_chunk(res, i, len, s) == NULL)
				return (NULL);
			i++;
		}
		s += (len - 1);
		if (*s == c && c != '\0')
			s++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	num;
	char	**res;

	num = num_chunks(s, c);
	res = (char **)malloc(num * sizeof(char *));
	if (!res)
		return (NULL);
	if (num > 0)
		return (ft_split2(res, s, c));
	res[0] = (char *)malloc(0);
	if (res[0] == NULL)
	{
		free(res);
		return (NULL);
	}
	res[0] = NULL;
	return (res);
}
