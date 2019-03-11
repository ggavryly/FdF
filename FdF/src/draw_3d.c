/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:05:51 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/06 15:05:52 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FdF.h"

//void	draw_lines(t_map *map)
//{
//	int i;
//	int j;
//	t_line line;
//
//	i = 0;
//	while (map->map[i])
//	{
//		j = 0;
//		while (map->map[i][j])
//		{
//			if ((j + 1) < map->map_w)
//			{
//				fill_line(&line, map->map[i][j], map->map[i][j + 1]);
//				draw_line(&line, map);
//			}
//			if ((i - 1) >= 0)
//			{
//				fill_line(&line, map->map[i][j], map->map[i - 1][j]);
//				draw_line(&line, map);
//			}
//			j++;
//		}
//		i++;
//	}
//}