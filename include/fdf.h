/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:28:43 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/20 22:28:46 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/include/libft.h"
# include <math.h>
# include "/usr/local/include/mlx.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# define WIN_WIDTH	1280
# define WIN_HEIGHT	1024
# define IS_NW(x) (x == '\n') ? (1) : (0)
# define MAX(x, y) (x >= y) ? (x) : (y)
# define PI			3.14
# define ESC			53
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2
# define RED			0xFF0000
# define BLUE		0x0000FF
# define WHITE		0xFFFFFF
# define YELLOW		0xFFE32C
# define LIGHT_BLUE	0x52ACFF

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int color;
}				t_point;

typedef struct	s_map
{
	int			grade_mod;
	int			max_alt;
	int			min_alt;
	double		zoom;
	int			map_h;
	int			map_w;
	int			s_x;
	int			s_y;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	double		cos_x;
	double		sin_x;
	double		cos_y;
	double		sin_y;
	double		cos_z;
	double		sin_z;
	void		*mlx;
	void		*win;
	void		*img;
	int			*img_arr;
	t_point		**points;
}				t_map;

typedef struct	s_line
{
	int			start;
	int			end;
	int			p0_color;
	int			p1_color;
	int			tmp_x;
	int			tmp_y;
	int			dx;
	int			dy;
	int			px;
	int			py;
}				t_line;

void			angle_x(t_map *map);
void			angle_y(t_map *map);
void			angle_z(t_map *map);
double			perce(int start, int end, int curr);
int				get_light(int start, int end, double percentage);
int				find_color(t_line curr);
int				find_color_z(int curr, int start, int end, int mode);
void			fill_color(t_map *map);
void			iso(t_map *map);
t_point			**init_cords(t_point **cords, t_map *map);
char			**cords_split(char *file, t_map *map);
void			map_default(t_map *map);
t_map			*read_file(char *av, t_map *map);
int				isometria(t_map *map);
void			fill_line(t_line *line, t_point xy0, t_point xy1);
void			fill_cord(t_map *map, char **file);
void			pixel_put(t_map *map, t_line line);
void			line(t_map *p, t_point pt1, t_point pt2);
void			draw_lines(t_map *map);
void			free_2_dim(char **cords);
void			free_points(t_map *map);
int				validate(t_map *map, char **cords);
void			fill_null(char ***cords, t_map *map);
void			choose_color(int mode, int color[2]);
void			instruction_put(t_map *map);

#endif
