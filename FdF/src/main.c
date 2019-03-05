#include "../include/FdF.h"
#include <unistd.h>
#include <stdio.h>

int deal_key(int key, void *param)
{
	if (key == ESC)
		exit(0);
	return (0);
}

int main(int ar, char const *av[])
{
	t_map   map;
	t_line  line;
	int		**cord;
	int 	gam;

	line.x0 = 500;
	line.y0 = 500;
	line.x1 = 997;
	line.y1 = 997;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	draw_line(&line, &map);
	mlx_key_hook(map.win, deal_key, NULL);
	mlx_loop(map.mlx);
	return 0;
}