/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:48:08 by ad-angel          #+#    #+#             */
/*   Updated: 2025/05/05 02:36:46 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	set_end_point(char **cur1, char **cur2, t_window *w, t_point s)
{
	t_point	e;
	int		dz;

	*cur2 = *cur1;
	if (**cur2 == '-')
		(*cur2)++;
	while (**cur2 >= '0' && **cur2 <= '9')
		(*cur2)++;
	if (*cur2 == *cur1)
		return (s);
	e.x = s.x;
	e.y = s.y;
	dz = string_to_num(*cur1, *cur2) * w->map_step;
	e.z = w->line_start.z + dz;
	if (**cur2 == ',')
	{
		if (*(*cur2 + 1) != '0' && *(*cur2 + 2) != 'x')
			return (e);
		(*cur2)++;
		e.color = hexdecimal_to_num(*cur2, *cur2 + 8);
		(*cur2) += 8;
	}
	else
		e.color = COLOR;
	return (e);
}

t_map_point	*prev_row_init(t_window *w, int drawing)
{
	t_map_point	*aux;

	if (drawing == 0)
		w->x_map_step_num++;
	if (w->prev_row == NULL)
	{
		w->prev_row = malloc(sizeof(t_map_point));
		aux = w->prev_row;
		aux->next = NULL;
	}
	else
	{
		aux = w->prev_row;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = malloc(sizeof(t_map_point));
		aux = aux->next;
		aux->next = NULL;
	}
	return (aux);
}

void	draw_transvesal_line(t_window w, t_line l, t_map_point **aux,
	int drawing)
{
	if (*aux == NULL)
		*aux = w.prev_row;
	else
		*aux = (*aux)->next;
	l.s = (*aux)->p;
	if (drawing == 1)
		mlx_line_put(w, l.s, l.e);
}

void	read_map_row(t_window *w, char *heights_row, int begin, int drawing)
{
	t_line		l;
	char		*cur1;
	char		*cur2;
	t_map_point	*aux;

	l.s = w->line_start;
	cur1 = heights_row;
	aux = NULL;
	while (*cur1 != '\n' && *cur1 != '\0')
	{
		l.e = set_end_point(&cur1, &cur2, w, l.s);
		if (cur2 > cur1)
		{
			if (begin)
				aux = prev_row_init(w, drawing);
			else
				draw_transvesal_line(*w, l, &aux, drawing);
			aux->p = l.e;
			l.s = l.e;
			l.s.x += w->map_step;
		}
		cur1 = cur2;
		if (*cur1 != '\n' && *cur1 != '\0')
			cur1++;
	}
}

void	mlx_pixel_put_ip(t_window w, t_point p, t_point s, t_point e)
{
	t_point	new_p;
	char	*point_addr;
	t_color	color;

	new_p.x = (p.x - p.y) * cos(IP_ANGLE);
	new_p.y = (p.x + p.y) * sin(IP_ANGLE) - p.z;
	new_p.z = p.z;
	if (new_p.x < 0 || new_p.x >= w.window_length
		|| new_p.y < 0 || new_p.y >= w.window_heigth)
		return ;
	point_addr = w.addr + (new_p.y * w.line_length
			+ new_p.x * (w.bits_per_pixel / 8));
	if (s.z == e.z)
		*(unsigned int *)point_addr = s.color;
	else
	{
		color.red = (s.color & 0xFF0000) + ((e.color & 0xFF0000)
				- (s.color & 0xFF0000)) / (e.z - s.z) * (p.z - s.z);
		color.green = (s.color & 0x00FF00) + ((e.color & 0x00FF00)
				- (s.color & 0x00FF00)) / (e.z - s.z) * (p.z - s.z);
		color.blue = (s.color & 0x0000FF) + ((e.color & 0x0000FF)
				- (s.color & 0x0000FF)) / (e.z - s.z) * (p.z - s.z);
		*(unsigned int *)point_addr = color.red + color.green + color.blue;
	}
}
