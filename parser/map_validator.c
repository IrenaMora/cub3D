#include "parser.h"
#include "../cub3d.h"

void	check_left(t_map *mapdata, int max_x, int max_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (mapdata->map[y][x] == WALL)
				break ;
			else if (mapdata->map[y][x] != NO_ELEMENT)
				define_error(mapdata, ERROR_MAP_AROUND);
			x++;
		}
		y++;
	}
}

void	check_right(t_map *mapdata, int max_x, int max_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < max_y)
	{
		x = max_x - 1;
		while (x >= 0)
		{
			if (mapdata->map[y][x] == WALL)
				break ;
			else if (mapdata->map[y][x] != NO_ELEMENT)
				define_error(mapdata, ERROR_MAP_AROUND);
			x--;
		}
		y++;
	}
}

void	check_top(t_map *mapdata, int max_x, int max_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
	{
		y = 0;
		while (y < max_y)
		{
			if (mapdata->map[y][x] == WALL)
				break ;
			else if (mapdata->map[y][x] != NO_ELEMENT)
				define_error(mapdata, ERROR_MAP_AROUND);
			y++;
		}
		x++;
	}
}

void	check_bottom(t_map *mapdata, int max_x, int max_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
	{
		y = max_y - 1;
		while (y >= 0)
		{
			if (mapdata->map[y][x] == WALL)
				break ;
			else if (mapdata->map[y][x] != NO_ELEMENT)
				define_error(mapdata, ERROR_MAP_AROUND);
			y--;
		}
		x++;
	}
}

void	validate_map(t_map *mapdata)
{
	int	max_x;
	int	max_y;

	max_x = mapdata->size_x;
	max_y = mapdata->size_y;
	check_left(mapdata, max_x, max_y);
	check_right(mapdata, max_x, max_y);
	check_top(mapdata, max_x, max_y);
	check_bottom(mapdata, max_x, max_y);
}
