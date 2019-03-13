/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:05:51 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/06 15:05:52 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	angle_x(t_map *map)
{
	map->cos_x = cos(PI / 180 * map->angle_x);
	map->sin_x = sin(PI / 180 * map->angle_x);
	printf("%lf-cos %lf-sin", map->cos_x, map->sin_x);
}

void	angle_y(t_map *map)
{
	map->cos_y = cos(PI / 180 * map->angle_y);
	map->sin_y = sin(PI / 180 * map->angle_y);
}

void	angle_z(t_map *map)
{
	map->cos_z = cos(PI / 180 * map->angle_z);
	map->sin_z = sin(PI / 180 * map->angle_z);
}


static	void	angle_man(t_map *map, double xyz[3], int i, int j)
{
	double tmp;

	tmp = xyz[0] * map->cos_x + xyz[1] * map->sin_x;
	xyz[1] = xyz[1] * map->cos_x - xyz[0] * map->sin_x;
	xyz[0] = tmp;

	tmp = xyz[1] * map->cos_y + xyz[2] * map->sin_y;
	xyz[2] = -xyz[1] * map->sin_y + xyz[2] * map->cos_y;
	xyz[1] = tmp;

	tmp = xyz[0] * map->cos_z + xyz[2] * map->sin_z;
	xyz[2] = -xyz[0] * map->sin_z + xyz[2] * map->cos_z;
	xyz[0] = tmp;

	map->points[i][j].x = (int)xyz[0];
	map->points[i][j].y = (int)xyz[1];
}

int 	isometria(t_map *map)
{
	int i;
	int j;
	double xyz[3];

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			xyz[0] = j;
			xyz[1] = i;
			xyz[2] = map->points[i][j].z;
			angle_man(map, xyz, i, j);
			map->points[i][j].x *= map->zoom;
			map->points[i][j].y *= map->zoom;
			map->points[i][j].x += map->s_x + WIN_WIDTH / 2;
			map->points[i][j].y += map->s_y + WIN_HEIGHT / 2;
			j++;
		}
		i++;
	}
	print_cord(map);
	return (0);
}
