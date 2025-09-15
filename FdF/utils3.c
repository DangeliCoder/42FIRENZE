/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:03 by ad-angel          #+#    #+#             */
/*   Updated: 2025/05/05 02:37:43 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_window *w, t_point line_start, int drawing)
{
	t_point		s;
	t_point		e;
	t_map_point	*aux;

	if (drawing == 0)
		w->y_map_step_num++;
	s = line_start;
	e = line_start;
	aux = w->prev_row;
	while (aux->next != NULL)
	{
		s = aux->p;
		aux = aux->next;
		e = aux->p;
		if (drawing == 1)
			mlx_line_put(*w, s, e);
	}
}

void	clear_window(t_window w)
{
	char	*point_addr;

	point_addr = w.addr;
	while (point_addr < (w.addr + w.window_heigth * w.line_length))
	{
		*(unsigned int *)point_addr = 0x000000;
		point_addr++;
	}
}

int	create_image(t_window *w, int drawing)
{
	char		*heights_row;
	int			begin;

	clear_window(*w);
	w->fd = open(w->filename, O_RDONLY);
	if (w->fd == -1)
		return (1);
	w->line_start.x = w->x0;
	w->line_start.y = w->y0;
	w->line_start.z = w->z0;
	begin = 1;
	heights_row = get_next_line(w->fd);
	while (heights_row != NULL)
	{
		read_map_row(w, heights_row, begin, drawing);
		begin = 0;
		draw_lines(w, w->line_start, drawing);
		w->line_start.y += w->map_step;
		free(heights_row);
		heights_row = get_next_line(w->fd);
	}
	close(w->fd);
	if (drawing == 1)
		mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}

void	mlx_window_init1(t_window *w, int argc, char **argv)
{
	w->mlx = mlx_init();
	w->filename = argv[1];
	w->win = mlx_new_window(w->mlx, 1920, 1080, w->filename);
	w->img = mlx_new_image(w->mlx, 1920, 1080);
	w->addr = mlx_get_data_addr(w->img, &(w->bits_per_pixel), &(w->line_length),
			&(w->endian));
	w->window_length = 1920;
	w->window_heigth = 1080;
	w->prev_row = NULL;
	if (argc >= 3)
		w->x0 = string_to_num2(argv[2]);
	else
		w->x0 = STARTX;
	if (argc >= 4)
		w->y0 = string_to_num2(argv[3]);
	else
		w->y0 = STARTY;
	if (argc >= 5)
		w->z0 = string_to_num2(argv[4]);
	else
		w->z0 = STARTZ;
}

void	mlx_window_init2(t_window *w, int argc, char **argv)
{
	int	map_step;

	if (argc >= 6)
	{
		map_step = string_to_num2(argv[5]);
		if (map_step > 0)
			w->map_step = map_step;
		else
			w->map_step = MAP_STEP;
	}
	else
		w->map_step = MAP_STEP;
	w->angle = 0;
	w->x_map_step_num = 0;
	w->y_map_step_num = 0;
}
