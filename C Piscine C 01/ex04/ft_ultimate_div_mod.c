/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:41:58 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/21 09:42:04 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	quot;
	int	mod;

	quot = *a / *b;
	mod = *a % *b;
	*a = quot;
	*b = mod;
}
/*
int	main(void)
{
	int	n;
	int	d;

	n = 13;
	d = 11;
	printf("%d %d\n", n, d);
	ft_ultimate_div_mod(&n, &d);
	printf("%d %d\n", n, d);
	return (0);
}*/
