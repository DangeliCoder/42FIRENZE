/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio <antonio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:38 by ad-angel          #+#    #+#             */
/*   Updated: 2026/09/23 14:58:38 by antonio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check(t_stacks stacks)
{
	char	*buf;
	int		error;
	int		c;

	buf = (char *)malloc(4 * sizeof(char));
	c = read_op(buf);
	while (c > 0)
	{
		error = exec_op(buf, &stacks);
		if (error)
		{
			free(buf);
			return (1);
		}
		c = read_op(buf);
	}
	free(buf);
	if (check_stacks(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
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

int	load_stack(int argc, char **argv, int *s, int *sh)
{
	int	n;
	int	i;

	*sh = 0;
	while (*sh < (argc - 1))
	{
		n = to_int(argv[argc - 1 - *sh]);
		i = 0;
		while (i < *sh)
		{
			if (s[i] == n)
				return (1);
			i++;
		}
		s[*sh] = n;
		(*sh)++;
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
		stacks.b = malloc((argc - 1) * sizeof(int));
		stacks.bh = 0;
		stacks.a = malloc((argc - 1) * sizeof(int));
		error = load_stack(argc, argv, stacks.a, &stacks.ah);
		if (!error)
			error = check(stacks);
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
