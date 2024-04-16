/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:22:40 by ad-angel          #+#    #+#             */
/*   Updated: 2023/11/07 14:22:43 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	tot_len(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;

	len = 0;
	if (s1 == NULL && s2 == NULL)
		return (len);
	if (s1 == NULL)
		s = (char *)s2;
	else if (*s1 != '\0' || s2 == NULL)
		s = (char *)s1;
	else
		s = (char *)s2;
	while (*s != '\0')
	{
		s++;
		len++;
		if (s1 != NULL)
			if (*s == '\0' && s == (s1 + len))
				if (s2 != NULL)
					s = (char *)s2;
	}
	return (len);
}

void	copy_str(char *s, char const *a, size_t *i)
{
	while (*a != '\0')
	{
		s[*i] = *a;
		(*i)++;
		a++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;

	s = malloc(tot_len(s1, s2) + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
		copy_str(s, s1, &i);
	if (s2 != NULL)
		copy_str(s, s2, &i);
	s[i] = '\0';
	return (s);
}
