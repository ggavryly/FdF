/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 04:34:17 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/13 04:34:18 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

void	fill_cords(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{

			map->points[i][j].x = (j - map->map_w / 2) * map->zoom;
			map->points[i][j].y = (i - map->map_h / 2) * map->zoom;
			map->points[i][j].x += map->s_x + WIN_WIDTH / 2;
			map->points[i][j].y += map->s_y + WIN_HEIGHT / 2;
			j++;
		}
		i++;
	}
}

