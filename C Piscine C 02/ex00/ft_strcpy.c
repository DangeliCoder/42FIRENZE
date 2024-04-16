/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:37:49 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/25 11:37:53 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*aux;

	aux = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
	return (aux);
}
/*
int	main(void)
{
	char	*str1;
	char	*aux;
	char	*str2;
	char	c;

	str1 = "Ciao Antonio!";
	aux = str1;
	c = 0;
	while (*aux != '\0')
	{
		c++;
		aux++;
	}
	str2 = malloc(sizeof(char) * (c + 1));
	str2 = ft_strcpy(str2, str1);
	printf("%s\n", str2);
	return (0);
}*/
