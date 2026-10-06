/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:01:50 by ad-angel          #+#    #+#             */
/*   Updated: 2026/10/01 04:14:26 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_stacks
{
	int	*a;
	int	ah;
	int	*b;
	int	bh;
}	t_stacks;

typedef struct s_push_swap
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_push_swap;

typedef struct s_rotates
{
	int	up;
	int	down;
	int	up_down;
}	t_rotates;

int			search_ind_min(int *s, int sh);
int			search_ind_b(t_stacks stacks, int x);
t_rotates	init_rotates(t_stacks stacks, int x, int y);
t_push_swap	exam_rotates(t_stacks stacks, t_rotates rot, int x, int y);
t_push_swap	min_op_search(t_push_swap *op, int sh);
void		stacks_rotates(t_stacks *stacks, t_push_swap op);
void		load_a(t_stacks *stacks);
int			check_sorted(int *s, int sh);
void		sort_small(t_stacks stacks);
void		mra(int *a, int ah, int c);
void		mrra(int *a, int ah, int c);
