/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:38 by ad-angel          #+#    #+#             */
/*   Updated: 2026/10/01 04:17:35 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap2.h"

void	sort(t_stacks stacks)
{
	int			x;
	int			y;
	t_rotates	rot;
	t_push_swap	*op;
	t_push_swap	cur_op;

	op = malloc(sizeof(t_push_swap) * stacks.ah);
	pb(stacks.a, &stacks.ah, stacks.b, &stacks.bh);
	while (stacks.ah > 0)
	{
		x = 0;
		while (x < stacks.ah)
		{
			y = search_ind_b(stacks, x);
			rot = init_rotates(stacks, x, y);
			op[x] = exam_rotates(stacks, rot, x, y);
			x++;
		}
		cur_op = min_op_search(op, stacks.ah);
		stacks_rotates(&stacks, cur_op);
		pb(stacks.a, &stacks.ah, stacks.b, &stacks.bh);
	}
	free(op);
	load_a(&stacks);
}

int	check_str(char *str, int *neg)
{
	int	i;

	*neg = 0;
	i = 0;
	if (str[i] == '-')
	{
		*neg = 1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (i);
}

int	to_int(char *str)
{
	int	i;
	int	neg;
	int	res;
	int	p10;

	i = check_str(str, &neg);
	res = 0;
	p10 = 1;
	i--;
	while (i >= 0)
	{
		if (str[i] == '-')
			break ;
		res += ((str[i] - 48) * p10);
		p10 *= 10;
		i--;
	}
	if (neg)
		return (-res);
	return (res);
}

int	set_stacks(int argc, char **argv, t_stacks *stacks)
{
	int	n;
	int	i;

	stacks->b = malloc((argc - 1) * sizeof(int));
	stacks->bh = 0;
	stacks->a = malloc((argc - 1) * sizeof(int));
	stacks->ah = 0;
	while (stacks->ah < (argc - 1))
	{
		n = to_int(argv[argc - 1 - stacks->ah]);
		i = 0;
		while (i < stacks->ah)
		{
			if (stacks->a[i] == n)
				return (1);
			i++;
		}
		stacks->a[stacks->ah] = n;
		stacks->ah++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			error;

	if (argc < 2)
		error = 1;
	else
	{
		error = set_stacks(argc, argv, &stacks);
		if (!error && !check_sorted(stacks.a, stacks.ah))
		{
			if (stacks.ah > 5)
				sort(stacks);
			else
				sort_small(stacks);
		}
		free(stacks.a);
		free(stacks.b);
	}
	if (error)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
