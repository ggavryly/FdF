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

double 		perce(int start, int end, int curr)
{
	double place;
	double dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int 		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int 		find_color(t_line curr)
{
	int     rgb[3];
	double  perc;

	if (curr.dx >= curr.dy)
		perc = perce(curr.start, curr.end, curr.tmp_x);
	else
		perc = perce(curr.start, curr.end, curr.tmp_y);
	rgb[0] = get_light((curr.p0_color >> 16) & 0xFF, (curr.p1_color >> 16) & 0xFF, perc);
	rgb[1] = get_light((curr.p0_color >> 8) & 0xFF, (curr.p1_color >> 8) & 0xFF, perc);
	rgb[2] = get_light((curr.p0_color) & 0xFF, (curr.p1_color) & 0xFF, perc);
	return ((rgb[0]<< 16) | (rgb[1] << 8) | rgb[2]);
}

int 		find_color_z(int curr, int start, int end)
{
	int     rgb[3];
	double  perc;

	perc = perce(start, end, curr);
	rgb[0] = get_light((YELLOW >> 16) & 0xFF, (LIGHT_BLUE >> 16) & 0xFF, perc);
	rgb[1] = get_light((YELLOW >> 8) & 0xFF, (LIGHT_BLUE >> 8) & 0xFF, perc);
	rgb[2] = get_light((YELLOW) & 0xFF, (LIGHT_BLUE) & 0xFF, perc);
	return ((rgb[0]<< 16) | (rgb[1] << 8) | rgb[2]);
}

char		**cords_split(char *file, t_map *map)
{
	int			i;
	size_t		j;
	char		**cords;
	int 		num;

	i = 0;
	j = 0;
	num = map->map_w * map->map_h;
	cords = (char **)malloc(sizeof(char *) * num + 1);
	cords[num] = NULL;
	while (i < num)
	{
		while ((*file == ' ' || *file == '\t' || *file == '\n') && *file != '\0')
			file++;
		while (file[j] != '\n' && file[j] != ' ' && *file != '\t' && *file != '\0')
			j++;
		if (!(*file))
			break;
		cords[i] = (char *)malloc((sizeof(char) * (j + 1)));
		cords[i][j] = '\0';
		ft_strncpy(cords[i], file, j);
		file += j;
		j = 0;
		i++;
	}
	return (cords);
}