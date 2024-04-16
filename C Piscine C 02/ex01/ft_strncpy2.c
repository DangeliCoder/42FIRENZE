/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:13:03 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/25 13:13:08 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*aux;
	char	i;

	i = 0;
	aux = dest;
	while (*src != '\0' && i < (char)n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (aux);
}

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Ciao Antonio!";
	str2 = malloc(sizeof(char) * 6);
//	str2 = ft_strncpy(str2, str1, 6);
	str2 = strncpy(str2, str1, 6);
	printf("%s\n", str2);
	return (0);
}
