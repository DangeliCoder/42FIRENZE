/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:32:16 by ad-angel          #+#    #+#             */
/*   Updated: 2025/05/04 05:07:20 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	vector_init(t_point s, t_point e, t_point *p)
{
	t_vector	v;

	v.dx = abs(e.x - s.x);
	v.dy = abs(e.y - s.y);
	v.dz = abs(e.z - s.z);
	*p = s;
	return (v);
}

void	mlx_line_put_based_on_x(t_window w, t_point s, t_point e)
{
	int			slope_error1;
	int			slope_error2;
	t_vector	v;
	t_point		p;

	v = vector_init(s, e, &p);
	slope_error1 = 2 * v.dy - v.dx;
	slope_error2 = 2 * v.dz - v.dx;
	while (p.x != e.x)
	{
		p.x += ((e.x - s.x) / v.dx);
		if (slope_error1 >= 0)
		{
			p.y += ((e.y - s.y) / v.dy);
			slope_error1 -= (2 * v.dx);
		}
		if (slope_error2 >= 0)
		{
			p.z += ((e.z - s.z) / v.dz);
			slope_error2 -= (2 * v.dx);
		}
		slope_error1 += (2 * v.dy);
		slope_error2 += (2 * v.dz);
		mlx_pixel_put_ip(w, p, s, e);
	}
}

void	mlx_line_put_based_on_y(t_window w, t_point s, t_point e)
{
	int			slope_error1;
	int			slope_error2;
	t_vector	v;
	t_point		p;

	v = vector_init(s, e, &p);
	slope_error1 = 2 * v.dx - v.dy;
	slope_error2 = 2 * v.dz - v.dy;
	while (p.y != e.y)
	{
		p.y += ((e.y - s.y) / v.dy);
		if (slope_error1 >= 0)
		{
			p.x += ((e.x - s.x) / v.dx);
			slope_error1 -= (2 * v.dy);
		}
		if (slope_error2 >= 0)
		{
			p.z += ((e.z - s.z) / v.dz);
			slope_error2 -= (2 * v.dy);
		}
		slope_error1 += (2 * v.dx);
		slope_error2 += (2 * v.dz);
		mlx_pixel_put_ip(w, p, s, e);
	}
}

void	mlx_line_put_based_on_z(t_window w, t_point s, t_point e)
{
	int			slope_error1;
	int			slope_error2;
	t_vector	v;
	t_point		p;

	v = vector_init(s, e, &p);
	slope_error1 = 2 * v.dy - v.dz;
	slope_error2 = 2 * v.dx - v.dz;
	while (p.z != e.z)
	{
		p.z += ((e.z - s.z) / v.dz);
		if (slope_error1 >= 0)
		{
			p.y += ((e.y - s.y) / v.dy);
			slope_error1 -= (2 * v.dz);
		}
		if (slope_error2 >= 0)
		{
			p.x += ((e.x - s.x) / v.dx);
			slope_error2 -= (2 * v.dz);
		}
		slope_error1 += (2 * v.dy);
		slope_error2 += (2 * v.dx);
		mlx_pixel_put_ip(w, p, s, e);
	}
}

void	mlx_line_put(t_window w, t_point s, t_point e)
{
	int	aux;
	int	dx;
	int	dy;
	int	dz;

	aux = s.x - w.xc;
	s.x = w.xc + aux * cos(w.angle) - (s.y - w.yc) * sin(w.angle);
	s.y = w.yc + aux * sin(w.angle) + (s.y - w.yc) * cos(w.angle);
	aux = e.x - w.xc;
	e.x = w.xc + aux * cos(w.angle) - (e.y - w.yc) * sin(w.angle);
	e.y = w.yc + aux * sin(w.angle) + (e.y - w.yc) * cos(w.angle);
	dx = abs(e.x - s.x);
	dy = abs(e.y - s.y);
	dz = abs(e.z - s.z);
	if (dx >= dy && dx >= dz)
		mlx_line_put_based_on_x(w, s, e);
	else if (dy >= dx && dy >= dz)
		mlx_line_put_based_on_y(w, s, e);
	else
		mlx_line_put_based_on_z(w, s, e);
}
