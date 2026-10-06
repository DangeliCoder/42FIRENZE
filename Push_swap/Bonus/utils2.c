/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:31:31 by ad-angel          #+#    #+#             */
/*   Updated: 2026/09/23 04:10:54 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stacks	*stacks)
{
	int	i;
	int	aux;

	if (stacks->ah == 0)
		return ;
	i = stacks->ah - 1;
	aux = stacks->a[i];
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = aux;
}

void	rb(t_stacks	*stacks)
{
	int	i;
	int	aux;

	if (stacks->bh == 0)
		return ;
	i = stacks->bh - 1;
	aux = stacks->b[i];
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = aux;
}

void	rr(t_stacks	*stacks)
{
	ra(stacks);
	rb(stacks);
}

void	rra(t_stacks	*stacks)
{
	int	i;
	int	aux;

	if (stacks->ah == 0)
		return ;
	i = 0;
	aux = stacks->a[i];
	while (i < (stacks->ah - 1))
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[stacks->ah - 1] = aux;
}

void	rrb(t_stacks	*stacks)
{
	int	i;
	int	aux;

	if (stacks->bh == 0)
		return ;
	i = 0;
	aux = stacks->b[i];
	while (i < (stacks->bh - 1))
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[stacks->bh - 1] = aux;
}
