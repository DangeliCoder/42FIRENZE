/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:41:56 by ad-angel          #+#    #+#             */
/*   Updated: 2025/05/05 04:18:12 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keys_management(int key, t_window *w)
{
	if (key == XK_KP_Add)
		zoom_in(w);
	if (key == XK_KP_Subtract)
		zoom_out(w);
	if (key == XK_Right)
		move_right(w);
	if (key == XK_Left)
		move_left(w);
	if (key == XK_Up)
		w->z0 += 20;
	if (key == XK_Down)
		w->z0 -= 20;
	if (key == XK_c)
		w->angle += (PI / 8);
	if (key == XK_a)
		w->angle -= (PI / 8);
}

int	handle_input(int key, t_window *w)
{
	char	*point_addr;

	if (key == XK_KP_Add || key == XK_KP_Subtract
		|| key == XK_c || key == XK_a
		|| (key >= XK_Left && key <= XK_Down))
	{
		keys_management(key, w);
		if (create_image(w, 1) == 1)
			exit(1);
		destroy_tools(w);
	}
	if (key == XK_Escape)
		exit(0);
	return (0);
}

int	handle_expose(t_window *param)
{
	if (create_image(param, 1) == 1)
		exit(1);
	destroy_tools(param);
	return (0);
}

int	handle_close(void *param)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_window	w;

	if (argc < 2)
	{
		write(2, "ERROR : too few parameters!\n", 28);
		return (1);
	}
	mlx_window_init1(&w, argc, argv);
	mlx_window_init2(&w, argc, argv);
	if (create_image(&w, 0) == 1)
	{
		write(2, "ERROR : input file not open!\nAborted PROGRAM.\n", 46);
		return (1);
	}
	destroy_tools(&w);
	w.xc = w.x0 + w.x_map_step_num * w.map_step / 2;
	w.yc = w.y0 + w.y_map_step_num * w.map_step / 2;
	mlx_key_hook(w.win, handle_input, &w);
	mlx_expose_hook(w.win, handle_expose, &w);
	mlx_hook(w.win, 17, 0, handle_close, &w);
	mlx_loop(w.mlx);
	return (0);
}
