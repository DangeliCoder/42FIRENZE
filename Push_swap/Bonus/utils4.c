/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:14:28 by ad-angel          #+#    #+#             */
/*   Updated: 2026/09/23 14:57:58 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	read_op(char *buf)
{
	int	i;
	int	c;
	int	c2;

	i = 0;
	c2 = read(0, buf, 1);
	if (c2 <= 0)
	{
		buf[0] = '\0';
		return (0);
	}
	c = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
		c2 = read(0, &buf[i], 1);
		if (c2 <= 0)
		{
			buf[0] = '\0';
			return (0);
		}
		c++;
	}
	return (c);
}

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\n' || s2[i] != '\n'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	exec_op(char *buf, t_stacks *stacks)
{
	if (!strncmp(buf, "sa\n", 3))
		sa(stacks);
	else if (!strncmp(buf, "sb\n", 3))
		sb(stacks);
	else if (!strncmp(buf, "ss\n", 3))
		ss(stacks);
	else if (!strncmp(buf, "pa\n", 3))
		pa(stacks);
	else if (!strncmp(buf, "pb\n", 3))
		pb(stacks);
	else if (!strncmp(buf, "ra\n", 3))
		ra(stacks);
	else if (!strncmp(buf, "rb\n", 3))
		rb(stacks);
	else if (!strncmp(buf, "rr\n", 3))
		rr(stacks);
	else if (!strncmp(buf, "rra\n", 4))
		rra(stacks);
	else if (!strncmp(buf, "rrb\n", 4))
		rrb(stacks);
	else if (!strncmp(buf, "rrr\n", 4))
		rrr(stacks);
	else
		return (1);
	return (0);
}

int	check_stacks(t_stacks stacks)
{
	int	i;

	if (stacks.bh != 0)
		return (0);
	i = 0;
	while (i < stacks.ah - 1)
	{
		if (stacks.a[i] < stacks.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
