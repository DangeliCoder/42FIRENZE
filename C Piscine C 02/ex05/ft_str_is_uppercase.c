/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:39:30 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 11:39:34 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str < 0x41 || *str > 0x5A)
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str;

	str = "CIAO";
	if (ft_str_is_uppercase(str))
		printf("La stringa contiene %s\n",
			"solo caratteri alfabetici maiuscoli.");
	else
		printf("La stringa contiene caratteri %s\n",
			"che non sono alfabetici maiuscoli.");
	return (0);
}*/
