/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:33:31 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/21 10:33:37 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		tab[i] ^= tab[size - 1 - i];
		tab[size - 1 - i] ^= tab[i];
		tab[i] ^= tab[size - 1 - i];
		i++;
	}
}
/*
int	main(void)
{
	int	tab[13];
	int	i;

	i = 0;
	while (i < 13)
	{
		tab[i] = i;
		i++;
	}
	ft_rev_int_tab(tab, 13);
	i = 0;
	printf("%d", tab[i]);
	i++;
	while (i < 13)
	{
		printf(" %d", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
