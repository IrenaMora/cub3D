#include <fcntl.h>
#include "parser.h"
#include "../cub3d.h"
#include "get_next_line.h"
#include "../memory_clear.h"

void	protect_map(t_map *map_data, int max_x, int max_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < max_x)
		map_data->map[0][x++] = WALL;
	x = 0;
	while (x < max_x)
		map_data->map[map_data->size_y - 1][x++] = WALL;
	y = 0;
	while (y < max_y)
		map_data->map[y++][0] = WALL;
	y = 0;
	while (y < max_y)
		map_data->map[y++][map_data->size_x - 1] = WALL;
}
