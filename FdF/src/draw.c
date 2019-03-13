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

#include "FdF.h"

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

void	draw_dx(t_line *line, t_map *map, int len)
{
	int d;

	d = -line->dx;
	len++;
	while (len--)
	{
		mlx_pixel_put(map->mlx, map->win, line->tmp_x, line->tmp_y, 0xFFF3);
		line->tmp_x += line->px;
		d += 2 * line->dy;
		if (d > 0)
		{
			d -= 2 * line->dx;
			line->tmp_y += line->py;
		}
	}
}

void	draw_dy(t_line *line, t_map *map, int len)
{
	int d;

	d = -line->dy;
	len++;
	while (len--)
	{
		mlx_pixel_put(map->mlx, map->win, line->tmp_x, line->tmp_y, 0xFFF3);
		line->tmp_y += line->py;
		d += 2 * line->dx;
		if (d > 0)
		{
			d -= 2 * line->dy;
			line->tmp_x += line->px;
		}
	}
}

int 	draw_line(t_map *map, t_point *xy0, t_point *xy1)
{
	t_line line;
	int len;

	fill_line(&line, xy0, xy1);
	len = MAX(line.dx, line.dy);
	line.tmp_x = line.x0;
	line.tmp_y = line.y0;
	if (len == 0)
		mlx_pixel_put(map->mlx, map->win, line.tmp_x, line.tmp_y, 0xFFF3);
	if (line.dy <= line.dx)
		draw_dx(&line, map, len);
	else
		draw_dy(&line, map, len);
	return (0);
}

void		draw_lines(t_map *map)
{
	int i;
	int j;

	printf("%d - st_x | %d - st_y\n",map->s_x, map->s_y);
	i = 0;
	print_cord(map);
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			if (j < map->map_w - 1)
				draw_line(map, &map->points[i][j], &map->points[i][j + 1]);
			if (i < map->map_h - 1)
				draw_line(map, &map->points[i + 1][j], &map->points[i][j]);
			j++;
		}
		i++;
	}
}