/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:10:08 by ad-angel          #+#    #+#             */
/*   Updated: 2026/10/01 02:47:02 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap2.h"

int	search_ind_min(int *s, int sh)
{
	int	i;
	int	ind;
	int	min;

	i = 0;
	min = s[i];
	ind = i;
	i++;
	while (i < sh)
	{
		if (s[i] < min)
		{
			min = s[i];
			ind = i;
		}
		i++;
	}
	return (ind);
}

int	search_ind_b(t_stacks stacks, int x)
{
	int	m;
	int	y;

	m = search_ind_min(stacks.b, stacks.bh);
	y = m;
	while (stacks.b[y] < stacks.a[x])
	{
		y++;
		if (y == stacks.bh)
			y = 0;
		if (y == m)
			break ;
	}
	if (y == 0)
		y = stacks.bh - 1;
	else
		y--;
	return (y);
}

t_push_swap	min_op_search(t_push_swap *op, int sh)
{
	int			x;
	t_push_swap	min_op;

	x = 0;
	min_op = op[x];
	while (x < sh)
	{
		if ((op[x].ra + op[x].rb + op[x].rr + op[x].rra + op[x].rrb
				+ op[x].rrr) < (min_op.ra + min_op.rb + min_op.rr
				+ min_op.rra + min_op.rrb + min_op.rrr))
			min_op = op[x];
		x++;
	}
	return (min_op);
}

void	load_a(t_stacks *stacks)
{
	int	i;

	i = search_ind_min(stacks->b, stacks->bh);
	while (i > 0)
	{
		rrb(stacks->b, stacks->bh, 1);
		i--;
	}
	while (stacks->bh > 0)
		pa(stacks->a, &stacks->ah, stacks->b, &stacks->bh);
}

int	check_sorted(int *s, int sh)
{
	int	i;

	i = 1;
	while (i < sh)
	{
		if (s[i] > s[i - 1])
			return (0);
		i++;
	}
	return (1);
}
