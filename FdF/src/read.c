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
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			w++;
			while (line[i] && line[i] != ' ' && line[i] != '\n')
				i++;
		}
		else if (line[i] == ' ')
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

t_point **read_cords(int **file, t_map *map)
{
	t_point **cords;
	int i;
	int j;

	i = 0;
	cords = (t_point **)malloc(sizeof(t_point *) * map->map_h + 1);
	cords[map->map_h] = NULL;
	cords = init_cords(cords, map);
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			cords[i][j].x = j;
			cords[i][j].y = i;
			cords[i][j].z = file[i][j];
			cords[i][j].color = 0xFFFFFF;
			j++;
		}
		i++;
	}
	return (cords);
}

t_map	*read_file(char *av, t_map *map)
{
	char	*file;
	int 	**map_c;

	file = file_to_line(av);
	map->map_w = analize_w(file);
	map->map_h = analize_h(file);
	map_c = init_map(map);
	map_c = fill_cord(map_c, map, file);
	map->points = read_cords(map_c, map);
	map->set = (t_point **)malloc(sizeof(t_point *) * map->map_h + 1);
	map->set[map->map_h] = NULL;
	map->set = init_cords(map->set, map);
	free(file);
	return (map);
}
