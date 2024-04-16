/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:13:25 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/25 16:13:31 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str < 0x41 || (*str > 0x5A && *str < 0x61) || *str > 0x7A)
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str;

	str = "StringadiprovaCiao";
	if (ft_str_is_alpha(str))
		printf("La stringa contiene solo caratteri alfabetici.\n");
	else
		printf("La stringa contiene caratteri che non sono alfabetici.\n");
	return (0);
}*/
