#include "FdF.h"

int deal_key(int key, t_map *map)
{
	if (key == ESC)
		exit(0);
	mlx_clear_window(map->mlx, map->win);
	if (key == UP || key == 126)
		map->s_y -= 10;
	else if (key == LEFT || key == 123)
		map->s_x -= 10;
	else if (key == DOWN || key == 125)
		map->s_y += 10;
	else if (key == RIGHT || key == 124)
		map->s_x += 10;
	else if (key == 89)
	{
		map->angle_x++;
		angle_x(map);
	}
	else if (key == 83)
	{
		map->angle_x--;
		angle_x(map);
	}
	else if (key == 91)
	{
		map->angle_y++;
		angle_y(map);
	}
	else if (key == 84)
	{
		map->angle_y--;
		angle_y(map);
	}
	else if (key == 92)
	{
		map->angle_z++;
		angle_z(map);
	}
	else if (key == 85)
	{
		map->angle_z--;
		angle_z(map);
	}
	isometria(map);
	draw_lines(map);
	return (0);
}

int	exit_k(void)
{
	exit(0);
}

void	print_cord(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->map_h)
	{
		j = 0;
		while (j < map->map_w)
		{
			printf("[%d][%d] - {x=%d} {y=%d} {z=%d}\n", i, j, map->points[i][j].x, map->points[i][j].y, map->points[i][j].z);
			j++;
		}
		i++;
	}
}

int main(int ar, char **av)
{
	t_map   map;

	map.mlx = mlx_init();
	map.s_x = 0;
	map.s_y = 0;
	map.zoom = 10;
	map.angle_x = 0;
	map.angle_y = 0;
	map.angle_z = 0;
	map.cos_x = 1;
	map.sin_x = 0;
	map.cos_y = 1;
	map.sin_y = 0;
	map.cos_z = 1;
	map.sin_z = 0;
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	map.img = mlx_new_image(map.mlx, WIN_WIDTH, WIN_HEIGHT);
//	fill_line(&line, xy0, xy1);
//	draw_line(&line, &map);
	read_file(av[1], &map);
	isometria(&map);
//	print_cord(&map);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, exit_k, &map);
	mlx_loop(map.mlx);
	return 0;
}