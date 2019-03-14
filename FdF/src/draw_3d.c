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

	tmp = xyz[0] * map->cos_x - xyz[1] * map->sin_x;
	xyz[1] = xyz[0] * map->sin_x + xyz[1] * map->cos_x;
	xyz[0] = tmp;

	tmp = xyz[1] * map->cos_y + xyz[2] * map->sin_y;
	xyz[2] = -xyz[1] * map->sin_y + xyz[2] * map->cos_y;
	xyz[1] = tmp;

	tmp = xyz[0] * map->cos_z + xyz[2] * map->sin_z;
	xyz[2] = -xyz[0] * map->sin_z + xyz[2] * map->cos_z;
	xyz[0] = tmp;
}

void	fill_img(t_map *map, t_point **set)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			if (set[i][j].x < WIN_WIDTH && set[i][j].x >= 0
			&& set[i][j].y < WIN_HEIGHT && set[i][j].y >= 0)
				map->img_arr[set[i][j].y * WIN_HEIGHT + set[i][j].x]= 0xFFFFFF;
			j++;
		}
		i++;
	}
}

int 	isometria(t_map *map)
{
	int i;
	int j;
	double xyz[3];
	char buf[125];

	i = 0;
	ft_bzero(map->img_arr, WIN_HEIGHT * WIN_WIDTH * (sizeof(int)));
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			xyz[0] = (j - map->map_w / 2) * map->zoom;
			xyz[1] = (i - map->map_h / 2) * map->zoom;
			xyz[2] = map->points[i][j].z * map->zoom;
			angle_man(map, xyz);
			xyz[0] += map->s_x + WIN_WIDTH / 2;
			xyz[1] += map->s_y + WIN_HEIGHT / 2;
			map->set[i][j].x = (int)xyz[0];
			map->set[i][j].y = (int)xyz[1];
			map->set[i][j].z = (int)xyz[2];
			map->set[i][j].color = 0xFFFFFF;
			j++;
		}
		i++;
	}
//	fill_img(map, set);
	draw_lines(map);
	sprintf(buf,"%d %d %d", map->angle_x, map->angle_y, map->angle_z);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_string_put(map->mlx, map->win, 10 , 10, 0xFF00FF, buf);
	return (0);
}
