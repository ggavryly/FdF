/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:08:20 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/20 00:08:21 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_2_dim(char **cords)
{
	int i;

	i = 0;
	while (cords[i])
	{
		free(cords[i]);
		i++;
	}
	free(cords);
}

void	free_points(t_map *map)
{
	int i;

	i = 0;
	while (i < map->map_h)
	{
		free(map->points[i]);
		i++;
	}
}
