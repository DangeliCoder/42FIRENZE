/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ad-angel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:31:09 by ad-angel          #+#    #+#             */
/*   Updated: 2025/05/05 04:07:12 by ad-angel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "mlx_int.h"
#include "get_next_line.h"

#define STARTX 1000
#define STARTY 0
#define STARTZ 0
#define IP_ANGLE 0.523598775
#define MAP_STEP 20
#define COLOR 0x808080
#define PI 3.14159265358979323846

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map_point
{
	t_point				p;
	struct s_map_point	*next;
}	t_map_point;

typedef struct s_window
{
	int			fd;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			window_length;
	int			window_heigth;
	int			x0;
	int			y0;
	int			z0;
	int			xc;
	int			yc;
	double		angle;
	int			map_step;
	int			x_map_step_num;
	int			y_map_step_num;
	t_point		line_start;
	int			endian;
	char		*filename;
	t_map_point	*prev_row;
}	t_window;

typedef struct s_vector
{
	int	dx;
	int	dy;
	int	dz;
}	t_vector;

typedef struct s_line
{
	t_point	s;
	t_point	e;
}	t_line;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

void	read_map_row(t_window *w, char *heights_row, int begin, int drawing);
void	mlx_pixel_put_ip(t_window w, t_point p, t_point s, t_point e);
void	mlx_line_put(t_window w, t_point s, t_point e);
void	mlx_window_init1(t_window *w, int argc, char **argv);
void	mlx_window_init2(t_window *w, int argc, char **argv);
int		create_image(t_window *w, int drawing);
void	destroy_tools(t_window *w);
int		string_to_num(char *start, char *end);
int		string_to_num2(char *string);
int		hexdecimal_to_num(char *start, char *end);
void	zoom_in(t_window *w);
void	zoom_out(t_window *w);
void	move_right(t_window *w);
void	move_left(t_window *w);
