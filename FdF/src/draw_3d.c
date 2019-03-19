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

int 	isometria(t_map *map)
{
	int i;
	int j;
	double xyz[3];
	char buf[50];

	i = 0;
	ft_bzero(map->img_arr, WIN_HEIGHT * WIN_WIDTH * (sizeof(int)));
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			xyz[0] = (j - map->map_w / 2.0) * map->zoom;
			xyz[1] = (i - map->map_h / 2.0) * map->zoom;
			xyz[2] = map->points[i][j].z * map->zoom;
			angle_man(map, xyz);
			xyz[0] += map->s_x;
			xyz[1] += map->s_y;
			map->points[i][j].x = (int)xyz[0];
			map->points[i][j].y = (int)xyz[1];
			j++;
		}
		i++;
	}
	draw_lines(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_string_put(map->mlx, map->win, 10 , 10, 0xFFFFFF, "INSTRUCTIONS:");
	mlx_string_put(map->mlx, map->win, 10 , 30, 0xFFFFFF, "Move: ");
	mlx_string_put(map->mlx, map->win, 10 , 50, 0xFFFFFF, "Rotation: (X) w|s");
	mlx_string_put(map->mlx, map->win, 110 , 70, 0xFFFFFF, "(Y) a|d");
	mlx_string_put(map->mlx, map->win, 110 , 90, 0xFFFFFF, "(Z) q|e");
	mlx_string_put(map->mlx, map->win, 10 , 110, 0xFFFFFF, "Zoom: +|-");
	mlx_string_put(map->mlx, map->win, 10 , 130, 0xFFFFFF, "PATRIOTIC_GRADIENT - U");
	ft_bzero(buf, 75);
	sprintf(buf,"| X - %d | Y - %d | Z - %d |", map->angle_x, map->angle_y, map->angle_z);
	mlx_string_put(map->mlx, map->win, (WIN_WIDTH / 2) - 200, 10, 0xFFFFFF, buf);
	return (0);
}
