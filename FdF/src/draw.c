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

int 	draw_line(t_line *line, t_map *map)
{
	int len;

	len = MAX(line->dx, line->dy);
	line->tmp_x = line->x0;
	line->tmp_y = line->y0;
	if (len == 0)
		mlx_pixel_put(map->mlx, map->win, line->tmp_x, line->tmp_y, 0xFFF3);
	if (line->dy <= line->dx)
		draw_dx(line, map, len);
	else
		draw_dy(line, map, len);
	return (0);
}

void		draw_horizontal(t_map *map)
{
	t_line line;
	int i;
	int j;

	i = 0;
	while (i < map->size_m)
	{
		j = 0;
		while (j < map->map_w - 1)
		{
			fill_line(&line, map->map[i], map->map[i + 1]);
			draw_line(&line, map);
			j++;
			i++;
		}
		i++;
	}
}

void		draw_vertical(t_map *map)
{
	t_line line;
	int i;
	int s;
	int j;

	j = 0;
	while (j < map->map_h)
	{
		i = j;
		s = 0;
		while (s < map->map_h - 1)
		{
			fill_line(&line, map->map[i], map->map[i + map->map_w]);
			draw_line(&line, map);
			i += map->map_w;
			s++;
		}
		j++;
	}
}

void		draw_lines(t_map *map)
{
	print_cord(map);
	draw_horizontal(map);
	draw_vertical(map);
}