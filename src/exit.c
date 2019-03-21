/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:08:20 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/20 00:08:21 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_2_dim(char **cords)
{
	int i;

	i = 0;
	if (cords)
	{
		while (cords[i])
		{
			free(cords[i]);
			i++;
		}
		free(cords);
	}
}

void		free_points(t_map *map)
{
	int i;

	i = 0;
	if (map->points)
	{
		while (i < map->map_h)
		{
			free(map->points[i]);
			i++;
		}
	}
}

int			find_color_z(int curr, int start, int end, int mode)
{
	int		rgb[3];
	int		color[2];
	double	perc;

	choose_color(mode, color);
	perc = perce(start, end, curr);
	rgb[0] = get_light((color[0] >> 16) & 0xFF, (color[1] >> 16) & 0xFF, perc);
	rgb[1] = get_light((color[0] >> 8) & 0xFF, (color[1] >> 8) & 0xFF, perc);
	rgb[2] = get_light((color[0]) & 0xFF, (color[1]) & 0xFF, perc);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void		choose_color(int mode, int color[2])
{
	if (mode == 1)
	{
		color[0] = WHITE;
		color[1] = RED;
	}
	else if (mode == 2)
	{
		color[0] = BLUE;
		color[1] = WHITE;
	}
	else if (mode == 32)
	{
		color[0] = YELLOW;
		color[1] = LIGHT_BLUE;
	}
}

void		instruction_put(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 15, 1, 0xFFFFFF, "-------------");
	mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFFF, "|INSTRUCTIONS|");
	mlx_string_put(map->mlx, map->win, 15, 21, 0xFFFFFF, "-------------");
	mlx_string_put(map->mlx, map->win, 10, 30, 0xFFFFFF, "|Move: arrows|");
	mlx_string_put(map->mlx, map->win, 10, 50, 0xFFFFFF, "|  Rotation: |");
	mlx_string_put(map->mlx, map->win, 10, 70, 0xFFFFFF, "|  (X) w|s   |");
	mlx_string_put(map->mlx, map->win, 10, 90, 0xFFFFFF, "|  (Y) a|d   |");
	mlx_string_put(map->mlx, map->win, 10, 110, 0xFFFFFF, "|  (Z) q|e   |");
	mlx_string_put(map->mlx, map->win, 10, 130, 0xFFFFFF, "|  Zoom: +|- |");
	mlx_string_put(map->mlx, map->win, 10, 150, 0xFFFFFF, "| Hue: 1|2|u |");
	mlx_string_put(map->mlx, map->win, 15, 162, 0xFFFFFF, "-------------");
}
