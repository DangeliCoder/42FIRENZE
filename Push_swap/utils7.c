/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 03:36:17 by antonio           #+#    #+#             */
/*   Updated: 2026/10/06 05:25:22 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap2.h"

void	sort_3(t_stacks stacks)
{
	int	ind_min;

	ind_min = search_ind_min(stacks.a, stacks.ah);
	if (ind_min == 0)
	{
		if (stacks.a[1] < stacks.a[2])
			sa(stacks.a, stacks.ah, 1);
	}
	else if (ind_min == 1)
	{
		rra(stacks.a, stacks.ah, 1);
		if (stacks.a[1] < stacks.a[2])
			sa(stacks.a, stacks.ah, 1);
	}
	else
	{
		ra(stacks.a, stacks.ah, 1);
		sa(stacks.a, stacks.ah, 1);
	}
	rra(stacks.a, stacks.ah, 1);
}

void	sort_4(t_stacks stacks)
{
	int	ind_min;

	ind_min = search_ind_min(stacks.a, stacks.ah);
	if (ind_min < 2)
		mrra(stacks.a, stacks.ah, ind_min + 1);
	else
		mra(stacks.a, stacks.ah, 3 - ind_min);
	pb(stacks.a, &stacks.ah, stacks.b, &stacks.bh);
	sort_3(stacks);
	pa(stacks.a, &stacks.ah, stacks.b, &stacks.bh);
}

void	sort_5(t_stacks stacks)
{
	int	ind_min;

	ind_min = search_ind_min(stacks.a, stacks.ah);
	if (ind_min < 3)
		mrra(stacks.a, stacks.ah, ind_min + 1);
	else
		mra(stacks.a, stacks.ah, 4 - ind_min);
	pb(stacks.a, &stacks.ah, stacks.b, &stacks.bh);
	sort_4(stacks);
	pa(stacks.a, &stacks.ah, stacks.b, &stacks.bh);
}

void	sort_small(t_stacks stacks)
{
	if (stacks.ah == 2)
		sa(stacks.a, stacks.ah, 1);
	else if (stacks.ah == 3)
		sort_3(stacks);
	else if (stacks.ah == 4)
		sort_4(stacks);
	else if (stacks.ah == 5)
		sort_5(stacks);
}
