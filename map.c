#include "cub3d.h"

int	map_get_pixel(t_mlxdata *mlxdata, int x, int y)
{
	return (mlxdata->map_data->map[y][x]);
}

int	map_get_color(int pixel)
{
	if (pixel == EMPTY)
		return (COLOR_EMPTY);
	else if (pixel == WALL)
		return (COLOR_WALL);
	else if (pixel == PLAYER_E || pixel == PLAYER_N \
	|| pixel == PLAYER_S || pixel == PLAYER_W)
		return (COLOR_PLAYER);
	return (UNKNOWN_RESULT);
}
