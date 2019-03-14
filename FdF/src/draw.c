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

void	pixel_put(t_map *map, t_line *line)
{
	if  (line->tmp_x < WIN_WIDTH && line->tmp_x >= 0
	&& line->tmp_y < WIN_HEIGHT && line->tmp_y >= 0)
		map->img_arr[line->tmp_y * WIN_WIDTH + line->tmp_x] = line->color;

}

void	draw_dx(t_line *line, t_map *map, int len)
{
	int d;

	d = -line->dx;
	len++;
	while (len--)
	{
		pixel_put(map, line);
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
		pixel_put(map, line);
		line->tmp_y += line->py;
		d += 2 * line->dx;
		if (d > 0)
		{
			d -= 2 * line->dy;
			line->tmp_x += line->px;
		}
	}
}

int 	draw_line(t_map *map, t_point xy0, t_point xy1)
{
	t_line line;
	int len;

	fill_line(&line, xy0, xy1);
	len = MAX(line.dx, line.dy);
	line.tmp_x = line.x0;
	line.tmp_y = line.y0;
	if (len == 0)
		pixel_put(map, &line);
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

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			if (j < map->map_w - 1)
				draw_line(map, map->set[i][j], map->set[i][j + 1]);
			if (i < map->map_h - 1)
				draw_line(map, map->set[i][j], map->set[i + 1][j]);
			j++;
		}
		i++;
	}
}