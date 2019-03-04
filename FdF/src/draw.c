/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:30:11 by ggavryly          #+#    #+#             */
/*   Updated: 2019/02/26 14:30:12 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

static int     test_arg(t_line *line)
{
	if (!(line->x0 < WIN_WIDTH && line->x0 >= 0))
		return (0);
	if (!(line->x1 < WIN_WIDTH && line->x1 >= 0))
		return (0);
	if (!(line->y0 < WIN_HEIGHT && line->y0 >= 0))
		return (0);
	if (!(line->y1 < WIN_HEIGHT && line->y1 >= 0))
		return (0);
	return (1);
}

static double angle_index(t_line *line)
{
	double tmp0;
	double tmp1;

	tmp0 = line->x1 - line->x0;
	tmp1 = line->y1 - line->y0;
	if (tmp1 > tmp0)
		return (fabs(tmp0 / tmp1));
	return (fabs(tmp1 / tmp0));
}

static double len_line(t_line *line)
{
	double tpm0;
	double tpm1;
	double res;

	tpm0 = line->x1 - line->x0;
	tpm1 = line->y1 - line->y0;
	res = pow(tpm0 ,2) + pow(tpm1 ,2);
	return (sqrt(res));
}

static double *vector_way_init(double *way, t_line *line)
{
	double len;
	double res;

	way = (double *)malloc(sizeof(double) * 2);
	way[0] = line->x1 - line->x0;
	way[1] = line->y1 - line->y0;
	len = sqrt(pow(way[0],2) + pow(way[1], 2));
	way[0] = way[0] / len;
	way[1] = way[1] / len;
	if (way[0] != 0)
		way[0] = (way[0] > 0) ? (1) : (-1);
	if (way[1] != 0)
		way[1] = (way[1] > 0) ? (1) : (-1);
	return (way);
}

static void draw_proc(t_line *line, double angle_ind, t_map *map)
{
	double	err;
	double	len;
	double	tmp_x;
	double	tmp_y;
	double	*vector_way;

	tmp_x = line->x0;
	tmp_y = line->y0;
	vector_way = vector_way_init(vector_way, line);
	len = len_line(line);
	err = 0.0;
	while (len > 0)
	{
		if (angle_ind == 1)
		{
			diagonal();
			continue ;
		}
		err += angle_ind;
		if (err > 0.5)
		{
			err--;
			tmp_y += vector_way[1];
		}
		else
			tmp_x += vector_way[0];
		mlx_pixel_put(map->mlx, map->win, (int)tmp_x, (int)tmp_y, 0xFF0000);
		len--;
	}
}

int 	draw_line(t_line *line, t_map *map)
{
	double angle_ind;

	if (test_arg(line))
	{
		angle_ind = angle_index(line);
		draw_proc(line, angle_ind, map);
		return (1);
	}
	return (0);
}