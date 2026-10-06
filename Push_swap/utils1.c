/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:41 by ad-angel          #+#    #+#             */
/*   Updated: 2024/09/09 12:21:43 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *a, int ah, int written)
{
	a[ah - 2] ^= a[ah - 1];
	a[ah - 1] ^= a[ah - 2];
	a[ah - 2] ^= a[ah - 1];
	if (written)
		write(1, "sa\n", 3);
}

void	sb(int *b, int bh, int written)
{
	b[bh - 2] ^= b[bh - 1];
	b[bh - 1] ^= b[bh - 2];
	b[bh - 2] ^= b[bh - 1];
	if (written)
		write(1, "sb\n", 3);
}

void	ss(int *a, int ah, int *b, int bh)
{
	sa(a, ah, 0);
	sb(b, bh, 0);
	write(1, "ss\n", 3);
}

void	pa(int *a, int *ah, int *b, int *bh)
{
	if (*bh < 1)
		return ;
	a[*ah] = b[*bh - 1];
	(*ah)++;
	(*bh)--;
	write(1, "pa\n", 3);
}

void	pb(int *a, int *ah, int *b, int *bh)
{
	if (*ah < 1)
		return ;
	b[*bh] = a[*ah - 1];
	(*bh)++;
	(*ah)--;
	write(1, "pb\n", 3);
}
