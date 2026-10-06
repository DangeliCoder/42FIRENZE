/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:31:31 by ad-angel          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:36 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(int *a, int ah, int written)
{
	int	i;
	int	aux;

	if (ah == 0)
		return ;
	i = ah - 1;
	aux = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = aux;
	if (written)
		write(1, "ra\n", 3);
}

void	rb(int *b, int bh, int written)
{
	int	i;
	int	aux;

	if (bh == 0)
		return ;
	i = bh - 1;
	aux = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = aux;
	if (written)
		write(1, "rb\n", 3);
}

void	rr(int *a, int ah, int *b, int bh)
{
	ra(a, ah, 0);
	rb(b, bh, 0);
	write(1, "rr\n", 3);
}

void	rra(int *a, int ah, int written)
{
	int	i;
	int	aux;

	if (ah == 0)
		return ;
	i = 0;
	aux = a[i];
	while (i < (ah - 1))
	{
		a[i] = a[i + 1];
		i++;
	}
	a[ah - 1] = aux;
	if (written)
		write(1, "rra\n", 4);
}

void	rrb(int *b, int bh, int written)
{
	int	i;
	int	aux;

	if (bh == 0)
		return ;
	i = 0;
	aux = b[i];
	while (i < (bh - 1))
	{
		b[i] = b[i + 1];
		i++;
	}
	b[bh - 1] = aux;
	if (written)
		write(1, "rrb\n", 4);
}
