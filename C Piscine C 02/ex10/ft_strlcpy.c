/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:03:44 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 16:03:49 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*aux;
	char	i;

	i = 0;
	aux = dest;
	while (*src != '\0' && i < (char)(size - 1))
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	i++;
	dest = aux;
	return ((unsigned int)i);
}
/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	l;
	char	n;

	str1 = "Ciao Antonio!";
	str2 = str1;
	l = 0;
	while (*str1 != '\0')
	{
		l++;
		str1++;
	}
	l++;
	str1 = str2;
	str2 = malloc(sizeof(char) * (l - 1));
	n = ft_strlcpy(str2, str1, (l - 1));
	if (n >= l)
		printf("%s\n", str2);
	else
		printf("Overflow!\n");
	return (0);
}*/
