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
	else if (key == 24)
	{
		map->zoom += 100;
	}
	else if (key == 27)
	{
		map->zoom -= 100;
	}
	else if (key == 34)
	{
		iso(map);
	}
	isometria(map);
	return (0);
}

int	exit_k(void)
{
	exit(0);
}


int mouse_move(int x, int y, t_map *map)
{
	if (map->camera_x < x)
	{
		map->angle_x--;
		angle_x(map);
	}
	else if (map->camera_x > x)
	{
		map->angle_x++;
		angle_x(map);
	}
	if (map->camera_y < y)
	{
		map->angle_y--;
		angle_y(map);
	}
	else if (map->camera_y > y)
	{
		map->angle_y++;
		angle_y(map);
	}
	if (map->camera_x > x && map->camera_y > y)
	{
		map->angle_z++;
		angle_z(map);
	}
	else if (map->camera_x < x && map->camera_y < y)
	{
		map->angle_z--;
		angle_z(map);
	}
	isometria(map);
	printf("camera_x - %d | camera_y - %d\n"
		   "       x - %d |        y - %d\n ", map->camera_x, map->camera_y, x , y);
	map->camera_x = x;
	map->camera_y = y;
	return (0);
}

int mouse_release(int button, int x, int y, t_map *map)
{
	ft_putstr("LYBLY");
	return (0);
}

int mouse_press(int button, int x, int y, t_map *map)
{
	map->camera_x = x;
	map->camera_y = y;
	return (0);
}

void	print_cord(t_map *map, int mode)
{
	int i;
	int j;

	i = 0;
	if (mode == 1)
	{
		while (i < map->map_h)
		{
			j = 0;
			while (j < map->map_w)
			{
				printf("[%d][%d] - {x=%d} {y=%d} {z=%d}\n", i, j, map->set[i][j].x, map->set[i][j].y, map->set[i][j].z);
				j++;
			}
			i++;
		}
	}
	else
	{	while (i < map->map_h)
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
}

int main(int ar, char **av)
{
	t_map   map;
	int		put1;
	int		put2;
	int		put3;

	map.mlx = mlx_init();
	map_default(&map);
	map.win = mlx_new_window(map.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	map.img = mlx_new_image(map.mlx, WIN_WIDTH, WIN_HEIGHT);
	map.img_arr = (int *)mlx_get_data_addr(map.img, &put1, &put2, &put3);
	read_file(av[1], &map);
	isometria(&map);
//	print_cord(&map);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 4, 0, mouse_press, &map);
	mlx_hook(map.win, 5, 0, mouse_release, &map);
	mlx_hook(map.win, 6, 0, mouse_move, &map);
	mlx_hook(map.win, 17, 0, exit_k, &map);
	mlx_loop(map.mlx);
	return 0;
}