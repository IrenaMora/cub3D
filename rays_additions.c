#include "cub3d.h"
#include "map.h"
#include "protect.h"
#include "drawing.h"

double	ray_sin(double deg)
{
	return (sin(deg * M_PI / 180));
}

double	ray_cos(double deg)
{
	return (cos(deg * M_PI / 180));
}

int	ray_is_wall(t_mlxdata *mlxdata, int x, int y)
{
	if (!protect_ray_outside(x, y))
		return (1);
	if (map_get_pixel(mlxdata, x, y) == WALL)
		return (1);
	return (0);
}

int	ray_get_side(t_mlxdata *mlxdata, double x, double y)
{
	if (map_get_pixel(mlxdata, x, y - PROTECT) != WALL)
		return (NORTH);
	else if (map_get_pixel(mlxdata, x, y + PROTECT) != WALL)
		return (SOUTH);
	else if (map_get_pixel(mlxdata, x - PROTECT, y) != WALL)
		return (WEST);
	else if (map_get_pixel(mlxdata, x + PROTECT, y) != WALL)
		return (EAST);
	else
		return (UNKNOWN_RESULT);
}

double	ray_get_percent(int side, double x, double y)
{
	if (side == NORTH || side == SOUTH)
		return (x - (int)(x));
	else
		return (1 - (y - (int)(y)));
}
