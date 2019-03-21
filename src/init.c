/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:52:04 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/05 17:52:06 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zoom_opt(t_map *map)
{
	int zoom;

	zoom = 1;
	if (map->map_h < map->map_w && map->map_h != 1)
		zoom = (WIN_WIDTH / 2) / map->map_h;
	else if (map->map_w != 1)
		zoom = (WIN_HEIGHT / 2) / map->map_w;
	if (zoom < 1)
		zoom = 1;
	return (zoom);
}

void	iso(t_map *map)
{
	map->zoom = zoom_opt(map);
	map->s_x = (int)(WIN_WIDTH / 2.0);
	map->s_y = (int)(WIN_HEIGHT / 2.0);
	map->angle_x = -30;
	map->angle_y = -30;
	map->angle_z = 30;
	map->cos_x = cos(PI / 180 * map->angle_x);
	map->cos_y = cos(PI / 180 * map->angle_y);
	map->cos_z = cos(PI / 180 * map->angle_z);
	map->sin_x = sin(PI / 180 * map->angle_x);
	map->sin_y = sin(PI / 180 * map->angle_y);
	map->sin_z = sin(PI / 180 * map->angle_z);
}

void	fill_cord(t_map *map, char **file)
{
	int i;
	int j;

	i = 0;
	map->min_alt = 0;
	map->max_alt = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			map->points[i][j].z = ft_atoi(file[i * map->map_w + j]);
			if (map->points[i][j].z < map->min_alt)
				map->min_alt = map->points[i][j].z;
			else if (map->points[i][j].z > map->max_alt)
				map->max_alt = map->points[i][j].z;
			j++;
		}
		i++;
	}
}

void	fill_line(t_line *line, t_point xy0, t_point xy1)
{
	line->p0_color = xy0.color;
	line->p1_color = xy1.color;
	line->tmp_x = xy0.x;
	line->tmp_y = xy0.y;
	line->dx = abs(xy1.x - xy0.x);
	line->dy = abs(xy1.y - xy0.y);
	line->px = xy1.x >= xy0.x ? 1 : -1;
	line->py = xy1.y >= xy0.y ? 1 : -1;
}

void	map_default(t_map *map)
{
	map->grade_mod = 1;
	map->cos_y = map->cos_x;
	map->angle_x = -30;
	map->angle_y = -30;
	map->angle_z = 30;
	map->s_x = (int)(WIN_WIDTH / 2.0);
	map->s_y = (int)(WIN_HEIGHT / 2.0);
	map->zoom = zoom_opt(map);
	map->cos_x = cos(PI / 180 * map->angle_x);
	map->cos_y = cos(PI / 180 * map->angle_y);
	map->cos_z = cos(PI / 180 * map->angle_z);
	map->sin_x = sin(PI / 180 * map->angle_x);
	map->sin_y = sin(PI / 180 * map->angle_y);
	map->sin_z = sin(PI / 180 * map->angle_z);
}
