/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:18:27 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/20 19:18:28 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_null(char ***cords, t_map *map)
{
	int i;
	int cord_num;

	cord_num = map->map_h * map->map_w;
	(*cords)[cord_num] = NULL;
	i = 1;
	while (i < cord_num)
	{
		(*cords)[i] = NULL;
		i++;
	}
}

int		validate(t_map *map, char **cords)
{
	int i;
	int cord_num;

	cord_num = map->map_h * map->map_w;
	i = 0;
	if (!cords)
	{
		errno = 1;
		return (0);
	}
	while (cords[i])
		i++;
	if (i != cord_num)
	{
		errno = 1;
		return (0);
	}
	return (1);
}
