/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:24:59 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 15:25:03 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	char	*aux;

	aux = str;
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 'a' + 'A';
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			str--;
			if (*str < '0' || (*str > '9' && *str < 'A')
				|| (*str > 'Z' && *str < 'a') || *str > 'z')
			{
				str++;
				*str = *str - 'a' + 'A';
			}
			else
				str++;
		}
		str++;
	}
	return (aux);
}
/*
int	main(void)
{
	char	str[100];
	char	*aux;
	char	i;

	aux = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	i = 0;
	while (*aux != '\0')
	{
		str[(int)i] = *aux;
		i++;
		aux++;
	}
	str[(int)i] = *aux;
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}*/
