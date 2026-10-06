/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:24:46 by ad-angel          #+#    #+#             */
/*   Updated: 2026/10/01 04:45:57 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	sa(int *a, int ah, int written);
void	sb(int *b, int bh, int written);
void	ss(int *a, int ah, int *b, int bh);
void	pa(int *a, int *ah, int *b, int *bh);
void	pb(int *a, int *ah, int *b, int *bh);
void	ra(int *a, int ah, int written);
void	rb(int *b, int bh, int written);
void	rr(int *a, int ah, int *b, int bh);
void	rra(int *a, int ah, int written);
void	rrb(int *b, int bh, int written);
void	rrr(int *a, int ah, int *b, int bh);
