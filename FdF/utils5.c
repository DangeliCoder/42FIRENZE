/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 03:54:05 by ad-angel          #+#    #+#             */
/*   Updated: 2025/05/05 04:07:47 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_window *w)
{
	w->map_step += 1;
	w->xc = w->x0 + w->x_map_step_num * w->map_step / 2;
	w->yc = w->y0 + w->y_map_step_num * w->map_step / 2;
}

void	zoom_out(t_window *w)
{
	if (w->map_step > 1)
	{
		w->map_step -= 1;
		w->xc = w->x0 + w->x_map_step_num * w->map_step / 2;
		w->yc = w->y0 + w->y_map_step_num * w->map_step / 2;
	}
}

void	move_right(t_window *w)
{
	w->x0 += (20 * sin(IP_ANGLE));
	w->y0 -= (20 * sin(IP_ANGLE));
	w->xc = w->x0 + w->x_map_step_num * w->map_step / 2;
	w->yc = w->y0 + w->y_map_step_num * w->map_step / 2;
}

void	move_left(t_window *w)
{
	w->x0 -= (20 * sin(IP_ANGLE));
	w->y0 += (20 * sin(IP_ANGLE));
	w->xc = w->x0 + w->x_map_step_num * w->map_step / 2;
	w->yc = w->y0 + w->y_map_step_num * w->map_step / 2;
}
