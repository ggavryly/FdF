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

#include "fdf.h"

double		perce(int start, int end, int curr)
{
	double place;
	double dist;

	place = curr - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			find_color(t_line curr)
{
	int		rgb[3];
	double	perc;

	if (curr.dx >= curr.dy)
		perc = perce(curr.start, curr.end, curr.tmp_x);
	else
		perc = perce(curr.start, curr.end, curr.tmp_y);
	rgb[0] = get_light((curr.p0_color >> 16) & 0xFF,
			(curr.p1_color >> 16) & 0xFF, perc);
	rgb[1] = get_light((curr.p0_color >> 8) & 0xFF,
			(curr.p1_color >> 8) & 0xFF, perc);
	rgb[2] = get_light((curr.p0_color) & 0xFF, (curr.p1_color) & 0xFF, perc);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void		fill_color(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			map->points[i][j].color = find_color_z(map->points[i][j].z,
					map->min_alt, map->max_alt, map->grade_mod);
			j++;
		}
		i++;
	}
}

char		**cords_split(char *f, t_map *map)
{
	size_t		i[2];
	char		**cords;
	int			num;

	i[0] = 0;
	num = map->map_w * map->map_h;
	cords = (char **)malloc(sizeof(char *) * num + 1);
	fill_null(&cords, map);
	while (i[0] < num && *f)
	{
		i[1] = 0;
		while ((*f == ' ' || *f == '\t' || *f == '\n') && *f != '\0')
			f++;
		while (f[i[1]] != '\n' && f[i[1]] != ' ' && f[i[1]] != '\t' && f[i[1]])
			i[1]++;
		if (!(*f))
			break ;
		cords[i[0]] = (char *)malloc((sizeof(char) * (i[1] + 1)));
		cords[i[0]][i[1]] = '\0';
		ft_strncpy(cords[i[0]++], f, i[1]);
		f += i[1];
	}
	if (*f && *f != '\n' && *f != ' ')
		return (NULL);
	return (cords);
}
