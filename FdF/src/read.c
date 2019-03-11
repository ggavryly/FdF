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
	if (!line[i] && line[i] != '\n')
		h++;
	return (h);
}

int		**init_cords(int **cords, t_map *map)
{
	int i;

	i = 0;
	while (i < map->size_m)
	{
		cords[i] = (int *)malloc(sizeof(int) * 1);
		i++;
	}
	return (cords);
}

int		**read_cords(char *file, t_map *map)
{
	int **cords;
	int i;
	int j;

	i = 0;
	j = 0;
	cords = (int **)malloc(sizeof(int *) * map->size_m + 1);
	cords[map->size_m] = NULL;
	cords = init_cords(cords, map);
	while (j < map->size_m)
	{
		if (file[i] != ' ' && file[i] != '\n')
		{
			cords[j][0] = ft_atoi(file + i);
			j++;
			while (file[i] != ' ' && file[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (cords);
}

t_map	*read_file(char *av, t_map *map)
{
	char *file;
	int **cords;

	file = file_to_line(av);
	map->map_w = analize_w(file);
	map->map_h = analize_h(file);
	map->size_m = map->map_w * map->map_h;
	cords = read_cords(file, map);
	map->map = init_map(map);
	fill_map(map, cords);
	return (map);
}
