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
	int j;

	i = 0;
	map = (int **)malloc(sizeof(int *) * mape->map_h + 1);
	map[mape->map_h] = NULL;
	while (i < mape->map_h)
	{
		j = 0;
		map[i] = (int *)malloc(sizeof(int) * mape->map_w);
		i++;
	}
	return (map);
}

static char	*find_num(char *file, int *n)
{
	int i;
	int flag;
	int res;

	i = *n;
	flag = 0;
	res = 0;
	while (file[i])
	{
		if (file[i] != '\n' && file[i] != ' ')
		{
			res = i;
			flag = 1;
		}
		while (file[i] && file[i] != '\n' && file[i] != ' ')
			i++;
		while (file[i] && (file[i] == '\n' || file[i] == ' '))
			i++;
		if (flag)
		{
			*n = i;
			break;
		}
	}
	return (file + res);
}

int		**fill_cord(int **cord, t_map *mape, char *file)
{
	int i;
	int j;
	int n;

	i = 0;
	n = 0;
	while (i < mape->map_h)
	{
		j = 0;
		while (j < mape->map_w)
		{
			cord[i][j] = ft_atoi(find_num(file, &n));
			j++;
		}
		i++;
	}
	return (cord);
}

void	fill_line(t_line *line, t_point xy0, t_point xy1)
{
	double dy;
	double dx;

	line->x0 = xy0.x;
	line->y0 = xy0.y;
	line->x1 = xy1.x;
	line->y1 = xy1.y;
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
	line->px = line->x1 >= line->x0 ? 1 : -1;
	line->py = line->y1 >= line->y0 ? 1 : -1;
	dx = line->dx;
	dy = line->dy;
	line->angle_kd = (fabs(dy / dx));
	line->angle_kd *= 2;
	line->angle_kd--;
	line->color = xy0.color;
}

void 	map_default(t_map *map)
{
	map->s_x = 0;
	map->s_y = 0;
	map->zoom = 10;
	map->angle_x = 30;
	map->angle_y = -30;
	map->angle_z = -30;
	map->cos_x = cos(PI / 180 * map->angle_x);
	map->sin_x = sin(PI / 180 * map->angle_x);
	map->cos_y = cos(PI / 180 * map->angle_y);
	map->sin_y = sin(PI / 180 * map->angle_y);
	map->cos_z = cos(PI / 180 * map->angle_z);
	map->sin_z = sin(PI / 180 * map->angle_z);
}



