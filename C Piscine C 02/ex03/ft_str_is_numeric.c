/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:53:35 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 10:53:43 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str < 0x30 || *str > 0x39)
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str;

	str = "1000a";
	if (ft_str_is_numeric(str))
		printf("La stringa contiene solo caratteri numerici.\n");
	else
		printf("La stringa contiene caratteri che non sono numerici.\n");
	return (0);
}*/
