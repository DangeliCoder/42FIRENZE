/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:21:41 by ad-angel          #+#    #+#             */
/*   Updated: 2026/09/23 04:07:34 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stacks	*stacks)
{
	stacks->a[stacks->ah - 2] ^= stacks->a[stacks->ah - 1];
	stacks->a[stacks->ah - 1] ^= stacks->a[stacks->ah - 2];
	stacks->a[stacks->ah - 2] ^= stacks->a[stacks->ah - 1];
}

void	sb(t_stacks	*stacks)
{
	stacks->b[stacks->bh - 2] ^= stacks->b[stacks->bh - 1];
	stacks->b[stacks->bh - 1] ^= stacks->b[stacks->bh - 2];
	stacks->b[stacks->bh - 2] ^= stacks->b[stacks->bh - 1];
}

void	ss(t_stacks	*stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_stacks	*stacks)
{
	if (stacks->bh < 1)
		return ;
	stacks->a[stacks->ah] = stacks->b[stacks->bh - 1];
	stacks->ah++;
	stacks->bh--;
}

void	pb(t_stacks	*stacks)
{
	if (stacks->ah < 1)
		return ;
	stacks->b[stacks->bh] = stacks->a[stacks->ah - 1];
	stacks->bh++;
	stacks->ah--;
}
