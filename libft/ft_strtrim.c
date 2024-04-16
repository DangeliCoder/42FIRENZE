/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:19:08 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/07 16:19:12 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	check(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	tot_len(char const *s, char const *set)
{
	int		start;
	size_t	len;

	start = 1;
	len = 0;
	while (*s != '\0')
	{
		if (!check(*s, set))
			start = 0;
		if (!start)
			len++;
		s++;
	}
	if (len == 0)
		return (len);
	s--;
	while (check(*s, set))
	{
		len--;
		s--;
	}
	return (len);
}

static void	copy_str(char *s, char const *s1, size_t len)
{
	while (len > 0)
	{
		*s = *s1;
		s++;
		s1++;
		len--;
	}
	*s = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*s;

	if (s1 == NULL)
		return (NULL);
	len = tot_len(s1, set);
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		if (!check(*s1, set))
			break ;
		s1++;
	}
	copy_str(s, s1, len);
	return (s);
}
