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

void	pixel_put(t_map *map, t_line line)
{
	if  (line.tmp_x < WIN_WIDTH && line.tmp_x >= 0 &&
	line.tmp_y < WIN_HEIGHT && line.tmp_y >= 0)
	{
		map->img_arr[line.tmp_y * WIN_WIDTH + line.tmp_x] = 0xFFFFFF & find_color(line);
	}

}

void	draw_dx(t_line line, t_map *map, int i)
{
	int d = -line.dx;

	i++;
	while(i--)
	{
		pixel_put(map, line);
		line.tmp_x += line.px;
		d += 2 * line.dy;
		if (d > 0) {
			d -= 2 * line.dx;
			line.tmp_y += line.py;
		}
	}
}

void	draw_dy(t_line line, t_map *map, int i)
{
	int d = -line.dy;

	i++;
	while(i--)
	{
		pixel_put(map, line);
		line.tmp_y += line.py;
		d += 2 * line.dx;
		if (d > 0)
		{
			d -= 2 * line.dy;
			line.tmp_x += line.px;
		}
	}
}

void line(t_map *map, t_point pt1, t_point pt2)
{
	t_line line;

	fill_line(&line, pt1, pt2);
	int i = MAX(line.dx, line.dy);
	if (i == 0)
		pixel_put(map, line);
	if (line.dy <= line.dx)
	{
		line.start = pt1.x;
		line.end = pt2.x;
		draw_dx(line, map, i);
	}
	else
	{
		line.start = pt1.y;
		line.end = pt2.y;
		draw_dy(line, map, i);
	}
}


void		draw_lines(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			if (j < map->map_w - 1)
				line(map, map->points[i][j], map->points[i][j + 1]);
			if (i < map->map_h - 1)
				line(map, map->points[i][j], map->points[i + 1][j]);
			j++;
		}
		i++;
	}
}