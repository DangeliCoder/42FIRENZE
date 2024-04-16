/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:17:34 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/26 12:17:38 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		if (*str < 0x20 || *str > 0x7E)
			return (0);
		str++;
	}
	return (1);
}
/*
int	main(void)
{
	char	*str;

	str = "1000a\n";
	if (ft_str_is_printable(str))
		printf("La stringa contiene solo caratteri stampabili.\n");
	else
		printf("La stringa contiene caratteri che non sono stampabili.\n");
	return (0);
}*/
