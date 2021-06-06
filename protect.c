#include "cub3d.h"
#include "rays.h"
#include "map.h"

void	protect_coordinates(t_mlxdata *mlxdata)
{
	if (mlxdata->player_x < 0)
		mlxdata->player_x = 0;
	else if (mlxdata->player_x > SIZE_X - 1)
		mlxdata->player_x = SIZE_X;
	if (mlxdata->player_y < 0)
		mlxdata->player_y = 0;
	else if (mlxdata->player_y > SIZE_Y - 1)
		mlxdata->player_y = SIZE_Y;
}

int	protect_drawing(int x, int y)
{
	if (x > SIZE_X - 1 || x < 0)
		return (0);
	else if (y > SIZE_Y - 1 || y < 0)
		return (0);
	return (1);
}

int	protect_player_outside(t_mlxdata *mlxdata, int angle, double x, double y)
{
	if (ray_protect(mlxdata, angle, x, y) <= 0.4)
		return (0);
	return (1);
}

int	protect_ray_outside(double x, double y)
{
	if (x > SIZE_X - 1 || x < 0)
		return (0);
	else if (y > SIZE_Y - 1 || y < 0)
		return (0);
	return (1);
}

double	protect_degrees(double degrees)
{
	while (degrees >= 360)
		degrees -= 360;
	return (degrees);
}
