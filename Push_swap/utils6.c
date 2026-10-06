/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:37:10 by ad-angel          #+#    #+#             */
/*   Updated: 2026/08/19 03:33:23 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap2.h"

t_rotates	init_rotates(t_stacks stacks, int x, int y)
{
	t_rotates	rot;

	if ((stacks.ah - 1 - x) > (stacks.bh - 1 - y))
		rot.up = stacks.ah - 1 - x;
	else
		rot.up = stacks.bh - 1 - y;
	if ((x + 1) > (y + 1))
		rot.down = x + 1;
	else
		rot.down = y + 1;
	if ((x + 1 + stacks.bh - 1 - y) < (stacks.ah - 1 - x + y + 1))
		rot.up_down = x + 1 + stacks.bh - 1 - y;
	else
		rot.up_down = stacks.ah - 1 - x + y + 1;
	return (rot);
}

t_push_swap	exam_up_rotates(t_stacks stacks, t_rotates rot, int x, int y)
{
	t_push_swap	op;

	if (rot.up == (stacks.ah - 1 - x))
	{
		op.rr = stacks.bh - 1 - y;
		op.ra = (stacks.ah - 1 - x) - (stacks.bh - 1 - y);
		op.rb = 0;
	}
	else
	{
		op.rr = stacks.ah - 1 - x;
		op.rb = (stacks.bh - 1 - y) - (stacks.ah - 1 - x);
		op.ra = 0;
	}
	op.rra = 0;
	op.rrb = 0;
	op.rrr = 0;
	return (op);
}

t_push_swap	exam_down_rotates(t_rotates rot, int x, int y)
{
	t_push_swap	op;

	if (rot.down == (x + 1))
	{
		op.rrr = y + 1;
		op.rra = (x + 1) - (y + 1);
		op.rrb = 0;
	}
	else
	{
		op.rrr = x + 1;
		op.rrb = (y + 1) - (x + 1);
		op.rra = 0;
	}
	op.ra = 0;
	op.rb = 0;
	op.rr = 0;
	return (op);
}

t_push_swap	exam_up_down_rotates(t_stacks stacks, t_rotates rot, int x, int y)
{
	t_push_swap	op;

	if (rot.up_down == (x + 1 + stacks.bh - 1 - y))
	{
		op.rb = stacks.bh - 1 - y;
		op.ra = 0;
		op.rra = x + 1;
		op.rrb = 0;
	}
	else
	{
		op.ra = stacks.ah - 1 - x;
		op.rb = 0;
		op.rrb = y + 1;
		op.rra = 0;
	}
	op.rr = 0;
	op.rrr = 0;
	return (op);
}

t_push_swap	exam_rotates(t_stacks stacks, t_rotates rot, int x, int y)
{
	t_push_swap	op;

	if (rot.up < rot.down && rot.up < rot.up_down)
		op = exam_up_rotates(stacks, rot, x, y);
	else if (rot.down < rot.up && rot.down < rot.up_down)
		op = exam_down_rotates(rot, x, y);
	else
		op = exam_up_down_rotates(stacks, rot, x, y);
	return (op);
}
