/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:14:28 by ad-angel          #+#    #+#             */
/*   Updated: 2026/08/10 23:22:20 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap2.h"

void	mra(int *a, int ah, int c)
{
	while (c > 0)
	{
		ra(a, ah, 1);
		c--;
	}
}

void	mrra(int *a, int ah, int c)
{
	while (c > 0)
	{
		rra(a, ah, 1);
		c--;
	}
}

void	mrb(int *b, int bh, int c)
{
	while (c > 0)
	{
		rb(b, bh, 1);
		c--;
	}
}

void	mrrb(int *b, int bh, int c)
{
	while (c > 0)
	{
		rrb(b, bh, 1);
		c--;
	}
}

void	stacks_rotates(t_stacks *stacks, t_push_swap op)
{
	mra(stacks->a, stacks->ah, op.ra);
	mrra(stacks->a, stacks->ah, op.rra);
	mrb(stacks->b, stacks->bh, op.rb);
	mrrb(stacks->b, stacks->bh, op.rrb);
	while (op.rr > 0)
	{
		rr(stacks->a, stacks->ah, stacks->b, stacks->bh);
		op.rr--;
	}
	while (op.rrr > 0)
	{
		rrr(stacks->a, stacks->ah, stacks->b, stacks->bh);
		op.rrr--;
	}
}
