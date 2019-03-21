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

#include "fdf.h"

void			angle_x(t_map *map)
{
	map->cos_x = cos(PI / 180 * map->angle_x);
	map->sin_x = sin(PI / 180 * map->angle_x);
}

void			angle_y(t_map *map)
{
	map->cos_y = cos(PI / 180 * map->angle_y);
	map->sin_y = sin(PI / 180 * map->angle_y);
}

void			angle_z(t_map *map)
{
	map->cos_z = cos(PI / 180 * map->angle_z);
	map->sin_z = sin(PI / 180 * map->angle_z);
}

static	void	angle_man(t_map *map, double xyz[3])
{
	double tmp;

	tmp = xyz[1] * map->cos_x + xyz[2] * map->sin_x;
	xyz[2] = -xyz[1] * map->sin_x + xyz[2] * map->cos_x;
	xyz[1] = tmp;
	tmp = xyz[0] * map->cos_y + xyz[2] * map->sin_y;
	xyz[2] = -xyz[0] * map->sin_y + xyz[2] * map->cos_y;
	xyz[0] = tmp;
	tmp = xyz[0] * map->cos_z - xyz[1] * map->sin_z;
	xyz[1] = xyz[0] * map->sin_z + xyz[1] * map->cos_z;
	xyz[0] = tmp;
}

int				isometria(t_map *map)
{
	int		ij[2];
	double	xyz[3];

	ij[0] = -1;
	ft_bzero(map->img_arr, WIN_HEIGHT * WIN_WIDTH * (sizeof(int)));
	while (++ij[0] < map->map_h)
	{
		ij[1] = 0;
		while (ij[1] < map->map_w)
		{
			xyz[0] = (ij[1] - map->map_w / 2.0) * map->zoom;
			xyz[1] = (ij[0] - map->map_h / 2.0) * map->zoom;
			xyz[2] = map->points[ij[0]][ij[1]].z * map->zoom;
			angle_man(map, xyz);
			xyz[0] += map->s_x;
			xyz[1] += map->s_y;
			map->points[ij[0]][ij[1]].x = (int)xyz[0];
			map->points[ij[0]][ij[1]].y = (int)xyz[1];
			ij[1]++;
		}
	}
	draw_lines(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	instruction_put(map);
	return (0);
}
