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

#include "FdF.h"

int		**init_map(t_map *mape)
{
	int **map;
	int i;

	i = 0;
	map = (int **)malloc(sizeof(int *) * mape->size_m + 1);
	map[mape->size_m] = NULL;
	while (i < mape->size_m)
	{
		map[i] = (int *)malloc(sizeof(int) * 3);
		map[i][0] = 0;
		map[i][1] = 0;
		map[i][2] = 53;
		i++;
	}
	return (map);
}

void	fill_map(t_map *map, int **file)
{
	int i;
	int j;
	int curr_x;
	int curr_y;

	i = 0;
	curr_x = 500;
	curr_y = 500;
	while (i < map->size_m)
	{
		j = 0;
		while (j < map->map_w)
		{
			map->map[i][0] = curr_x;
			map->map[i][1] = curr_y;
			map->map[i][2] = file[i][0];
			curr_x += 10;
			i++;
			j++;
		}
		curr_x = 500;
		curr_y += 10;
	}
}

void	fill_line(t_line *line, int *xy0, int *xy1)
{
	double dy;
	double dx;

	if (!xy0 || !xy1)
		return;
	line->x0 = xy0[0];
	line->y0 = xy0[1];
	line->x1 = xy1[0];
	line->y1 = xy1[1];
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
	line->px = line->x1 >= line->x0 ? 1 : -1;
	line->py = line->y1 >= line->y0 ? 1 : -1;
	dx = line->dx;
	dy = line->dy;
	line->angle_kd = (fabs(dy / dx));
	line->angle_kd *= 2;
	line->angle_kd--;
}
