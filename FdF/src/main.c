#include "FdF.h"

int deal_key(int key, void *param)
{
	if (key == ESC)
		exit(0);
	return (0);
}

void	print_cord(t_map *map)
{
	int i;
	int ij;

	i = 0;
	ij = map->map_h * map->map_w;
	while (i < ij)
	{
		printf("[%d] - {x=%d} {y=%d} {z=%d}\n", i, map->map[i][0], map->map[i][1], map->map[i][2]);
		i++;
	}
}

int main(int ar, char **av)
{
	t_map   map;

	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
//	fill_line(&line, xy0, xy1);
//	draw_line(&line, &map);
	read_file(av[1], &map);
	draw_lines(&map);
//	print_cord(&map);
	mlx_key_hook(map.win, deal_key, NULL);
	mlx_loop(map.mlx);
	return 0;
}