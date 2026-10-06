/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:24:46 by ad-angel          #+#    #+#             */
/*   Updated: 2026/09/23 14:24:48 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stacks
{
	int	*a;
	int	ah;
	int	*b;
	int	bh;
}	t_stacks;

void	sa(t_stacks	*stacks);
void	sb(t_stacks	*stacks);
void	ss(t_stacks	*stacks);
void	pa(t_stacks	*stacks);
void	pb(t_stacks	*stacks);
void	ra(t_stacks	*stacks);
void	rb(t_stacks	*stacks);
void	rr(t_stacks	*stacks);
void	rra(t_stacks	*stacks);
void	rrb(t_stacks	*stacks);
void	rrr(t_stacks	*stacks);

int		read_op(char *buf);
int		exec_op(char *buf, t_stacks *stacks);
int		check_stacks(t_stacks stacks);
