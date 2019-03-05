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



t_dt 	*read_file(char **av, t_map *map)
{
	int map_w;
	int map_h;
	int i;
	char *line;

	map_h = 0;
	map_w = 0;
	i = 0;
	line = file_to_line(av[1]);
	while (line[i])
	{
		if (IS_SPC(line[i]))
			i++;
		map_w++;
		i++;
	}
	while (line[i])
	{
		if (IS_NW(line[i]))
			map_h++;
		i++;
	}
	map->map_h = map_h;
	map->map_w = map_w;

}
