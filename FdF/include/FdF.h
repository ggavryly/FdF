/* ************************************************************************** *//*                                                                            *//*                                                        :::      ::::::::   *//*   FdF.h                                              :+:      :+:    :+:   *//*                                                    +:+ +:+         +:+     *//*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        *//*                                                +#+#+#+#+#+   +#+           *//*   Created: 2019/02/26 11:19:16 by ggavryly          #+#    #+#             *//*   Updated: 2019/02/26 11:19:17 by ggavryly         ###   ########.fr       *//*                                                                            *//* ************************************************************************** */#ifndef FDF_H# define FDF_H# include "../libft/include/libft.h"# include <math.h># include "mlx.h"# define WIN_WIDTH	1000# define WIN_HEIGHT	1000# define START		500# define IS_SPC(x) (x == ' ') ? (1) : (0)# define IS_NW(x) (x == '\n') ? (1) : (0)# define ESC        53# define UP         13# define DOWN       1# define LEFT       0# define RIGHT      2typedef struct	s_dt{	int			x;	int			y;	struct s_dt	*right;	struct s_dt *up;}				t_dt;typedef struct	s_map{	int 		map_h;	int 		map_w;	void        *mlx;	void        *win;	void        *img;	t_dt		*head;}				t_map;typedef struct  s_line{	int		x0;	int		y0;	int		x1;	int		y1;	int 	dx;	int 	dy;	int 	px;	int 	py;	int 	tmp_x;	int 	tmp_y;	int		angle_k;}               t_line;t_dt			*read_file(char **av, t_map *map);void            init_line(void *line, void *win_ptr);int 	        draw_line(t_line *line, t_map *map);#endif