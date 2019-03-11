#include "FdF.h"

int deal_key(int key, void *param)
{
	if (key == ESC)
		exit(0);
	return (0);
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