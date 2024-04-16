/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:11:49 by ad-angel          #+#    #+#             */
/*   Updated: 2023/09/21 11:11:52 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *n1, int *n2)
{
	if (n1 == n2)
		return ;
	*n1 ^= *n2;
	*n2 ^= *n1;
	*n1 ^= *n2;
}

void	quicksort(int *tab, int s, int e)
{
	int	i;
	int	p;

	if (s >= e)
		return ;
	p = s;
	i = s;
	while (i < e)
	{
		if (tab[i] < tab[e])
		{
			swap(&tab[i], &tab[p]);
			p++;
		}
		i++;
	}
	swap(&tab[p], &tab[e]);
	quicksort(tab, s, p - 1);
	quicksort(tab, p + 1, e);
}

void	ft_sort_int_tab(int *tab, int size)
{
	quicksort(tab, 0, size - 1);
}
/*
int	main(void)
{
	int	tab[13];
	int	i;

	i = 0;
	while (i < 13)
	{
		tab[i] = 12 - i;
		if (i == 6)
			tab[i] = 5;
		printf(" %d", tab[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(tab, 13);
	i = 0;
	while (i < 13)
	{
		printf(" %d", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
