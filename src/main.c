/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggavryly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 21:45:35 by ggavryly          #+#    #+#             */
/*   Updated: 2019/03/20 21:45:42 by ggavryly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_spin(int key, t_map *map)
{
	if (key == UP || key == DOWN)
	{
		if (key == UP)
			map->angle_x -= 2;
		else
			map->angle_x += 2;
		angle_x(map);
	}
	if (key == LEFT || key == RIGHT)
	{
		if (key == LEFT)
			map->angle_y -= 2;
		else
			map->angle_y += 2;
		angle_y(map);
	}
	if (key == 14 || key == 12)
	{
		if (key == 14)
			map->angle_z += 2;
		else
			map->angle_z -= 2;
		angle_z(map);
	}
	return (0);
}

void	gradient_mode(t_map *map, int key)
{
	if (key == 19 || key == 84)
		map->grade_mod = 2;
	else if (key == 18 || key == 83)
		map->grade_mod = 1;
	else if (key == 32)
		map->grade_mod = 32;
	fill_color(map);
}

int		exit_k(t_map *map)
{
	if (errno == 2)
		ft_putstr("usage: ./FdF [file]\n");
	else if (errno == 1 || errno == 3)
		ft_putstr("error: invalid file\n");
	if (errno == 3 || errno == 2)
		exit(0);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_image(map->mlx, map->img);
	free_points(map);
	exit(0);
}

int		deal_key(int key, t_map *map)
{
	if (key == ESC)
		exit_k(map);
	mlx_clear_window(map->mlx, map->win);
	if (key == 126)
		map->s_y -= 5;
	else if (key == 123)
		map->s_x -= 10;
	else if (key == 125)
		map->s_y += 10;
	else if (key == 124)
		map->s_x += 5;
	else if (key == 34)
		iso(map);
	else if ((key == 24 || key == 69) && map->zoom)
		map->zoom++;
	else if ((key == 27 || key == 78) && map->zoom > 1)
		map->zoom--;
	else if (key == 18 || key == 19 || key == 83 || key == 84 || key == 32)
		gradient_mode(map, key);
	else if (key == UP || key == DOWN
	|| key == LEFT || key == RIGHT || key == 12 || key == 14)
		key_spin(key, map);
	isometria(map);
	return (0);
}

int		main(int ar, char **av)
{
	t_map	map;
	int		put1;
	int		put2;
	int		put3;

	if (ar != 2)
	{
		errno = 2;
		exit_k(&map);
	}
	if (!read_file(av[1], &map))
		exit_k(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	map.img = mlx_new_image(map.mlx, WIN_WIDTH, WIN_HEIGHT);
	map.img_arr = (int *)mlx_get_data_addr(map.img, &put1, &put2, &put3);
	map_default(&map);
	isometria(&map);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, exit_k, &map);
	mlx_loop(map.mlx);
	return (0);
}
