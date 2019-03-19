#include "FdF.h"

int key_spin(int key, t_map *map)
{
	if (key == UP)
	{
		map->angle_x -= 2;
		angle_x(map);
	}
	else if (key == DOWN)
	{
		map->angle_x += 2;
		angle_x(map);
	}
	if (key == LEFT)
	{
		map->angle_y -= 2;
		angle_y(map);
	}
	else if (key == RIGHT)
	{
		map->angle_y += 2;
		angle_y(map);
	}
	if (key == 14)
	{
		map->angle_z += 2;
		angle_z(map);
	}
	else if (key == 12)
	{
		map->angle_z -= 2;
		angle_z(map);
	}
	return (0);
}

int deal_key(int key, t_map *map)
{
	if (key == ESC)
	{
		free_points(map);
		exit(0);
	}
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
	else if (key == 24 && map->zoom)
		map->zoom++;
	else if (key == 27 && map->zoom > 1)
		map->zoom--;
	else if (key == UP || key == DOWN
	|| key == LEFT || key == RIGHT || key == 12 || key == 14)
		key_spin(key, map);
	isometria(map);
	return (0);
}

int	exit_k(t_map *map)
{
	free_points(map);
	exit(0);
}

int main(int ar, char **av)
{
	t_map   map;
	int		put1;
	int		put2;
	int		put3;

	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	map.img = mlx_new_image(map.mlx, WIN_WIDTH, WIN_HEIGHT);
	map.img_arr = (int *)mlx_get_data_addr(map.img, &put1, &put2, &put3);
	read_file(av[1], &map);
	map_default(&map);
	isometria(&map);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, exit_k, &map);
	mlx_loop(map.mlx);
	return 0;
}