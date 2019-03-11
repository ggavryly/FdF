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
		if (IS_NW(line[i]))
			break ;
		while (line[i] && line[i] != ' ')
			i++;
		w++;
		while (line[i] && line[i] == ' ')
			i++;
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
	return (h);
}

t_map	*read_file(char *av, t_map *map)
{
	char *file;
	char **cords;

	file = file_to_line(av);
	map->map_h = analize_h(file);
	map->map_w = analize_w(file);
	cords = ft_strsplit(file, ' ');
	map->map = init_map(map->map_h, map->map_w);
	fill_map(map, cords);
	return (map);
}
