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

static void	angle_k(t_line *line, int *d)
{
	if (line->dy <= line->dx)
	{
		line->tmp_x = line->x0 + line->px;
		line->tmp_y = line->y0;
		line->angle_k = (line->dy << 1) - line->dx;
		d[0] = (line->dy << 1) - line->dx;
		d[1] = (line->dy - line->dx) << 1;
	}
	else
	{
		line->tmp_y = line->y0 + line->py;
		line->tmp_x = line->x0;
		line->angle_k = (line->dx << 1) - line->dy;
		d[0] = (line->dx << 1) - line->dx;
		d[1] = (line->dx - line->dy) << 1;
	}
}

void	draw_dx(t_line *line, t_map *map, int color, int *d)
{
	int i;

	i = 1;
	mlx_pixel_put(map->mlx, map->win, line->x0, line->y0, color);
	while(i <= line->dx)
	{
		if (line->angle_k > 0)
		{
			line->angle_k += d[1];
			line->tmp_y += line->py;
		}
		else
			line->angle_k += d[0];
		mlx_pixel_put(map->mlx, map->win, line->tmp_x, line->tmp_y, color);
		i++;
		line->tmp_x += line->px;
	}
}

void	draw_dy(t_line *line, t_map *map, int color, int *d)
{
	int i;

	i = 1;
	mlx_pixel_put(map->mlx, map->win, line->x0, line->y0, color);
	while(i <= line->dy)
	{
		if (line->angle_k > 0)
		{
			line->angle_k += d[1];
			line->tmp_x += line->px;
		}
		else
			line->angle_k += d[0];
		mlx_pixel_put(map->mlx, map->win, line->tmp_x, line->tmp_y, color);
		i++;
		line->tmp_y += line->py;
	}
}

int 	draw_line(t_line *line, t_map *map)
{
	int d[2];

	if (test_arg(line))
	{
		line->px = line->x1 >= line->x0 ? 1 : -1;
		line->py = line->y1 >= line->y0 ? 1 : -1;
		line->dx = abs(line->x1 - line->x0);
		line->dy = abs(line->y1 - line->y0);
		angle_k(line, d);
		if (line->dy <= line->dx)
			draw_dx(line, map, 30000, d);
		else
			draw_dy(line, map, 30000, d);
		return (1);
	}
	return (0);
}