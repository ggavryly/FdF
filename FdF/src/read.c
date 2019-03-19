/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 12:40:53 by ggavryly          #+#    #+#             */
/*   Updated: 2019/02/26 12:40:55 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int analize_w(const char *line)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t')
		{
			w++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
		}
		else if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (line[i] == '\n')
			break ;
	}
	return (w);
}

static int analize_h(const char *line)
{
	int i;
	int h;

	i = 0;
	h = 0;
	while (line[i])
	{
		if (IS_NW(line[i]))
			h++;
		i++;
	}
	if (!line[i] && line[i - 1] != '\n')
		h++;
	return (h);
}

t_point		**init_cords(t_point **cords, t_map *map)
{
	int i;

	i = 0;
	while (i < map->map_h)
	{
		cords[i] = (t_point *)malloc(sizeof(t_point) * map->map_w);
		i++;
	}
	return (cords);
}

t_point **read_cords(t_map *map)
{
	t_point **cords;

	cords = (t_point **)malloc(sizeof(t_point *) * map->map_h + 1);
	cords[map->map_h] = NULL;
	cords = init_cords(cords, map);
	return (cords);
}

void	fill_color(t_map *map)
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
					map->min_alt, map->max_alt);
			j++;
		}
		i++;
	}


}

t_map	*read_file(char *av, t_map *map)
{
	char	*file;
	char 	**cords;

	file = file_to_line(av);
	map->map_w = analize_w(file);
	map->map_h = analize_h(file);
	cords = cords_split(file, map);
	map->points = read_cords(map);
	fill_cord(map, cords);
	fill_color(map);
	free_2_dim(cords);
	free(file);
	return (map);
}
