/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:19:21 by ad-angel          #+#    #+#             */
/*   Updated: 2025/04/29 02:40:57 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_tools(t_window *w)
{
	t_map_point	*aux;

	while (w->prev_row != NULL)
	{
		aux = w->prev_row;
		w->prev_row = aux->next;
		free(aux);
	}
}

int	string_to_num(char *start, char *end)
{
	int	power;
	int	number;
	int	i;

	if (*start == '-')
	{
		power = -1;
		start++;
	}
	else
		power = 1;
	if (start == end)
		return (0);
	power *= (int)pow(10, (double)(end - start) - 1);
	number = 0;
	i = 0;
	while (abs(power) >= 1)
	{
		number += (power * (start[i] - 0x30));
		i++;
		power /= 10;
	}
	return (number);
}

int	string_to_num2(char *string)
{
	int		number;
	int		i;
	char	minus;

	number = 0;
	i = 0;
	minus = 0;
	if (string[i] == '-')
	{
		minus = 1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		number = number * 10 + (string[i] - '0');
		i++;
	}
	if (minus)
		number = -number;
	return (number);
}

int	hexdecimal_digit_to_num(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)(c - 0x30));
	if (c >= 'a' && c <= 'f')
		return ((int)(c - 0x61) + 10);
	if (c >= 'A' && c <= 'F')
		return ((int)(c - 0x41) + 10);
	return (0);
}

int	hexdecimal_to_num(char *start, char *end)
{
	int	power;
	int	number;

	start += 2;
	if (start >= end)
		return (0);
	power = (int)pow(16, (double)(end - start) - 1);
	number = 0;
	while (power >= 1)
	{
		number += (power * hexdecimal_digit_to_num(*start));
		start++;
		power /= 16;
	}
	return (number);
}
