#include "cub3d.h"
#include "map.h"
#include "rays.h"
#include "protect.h"
#include "drawing.h"

int	is_pairing(t_mlxdata *mlxdata, double x, double y, int something)
{
	if (map_get_pixel(mlxdata, x, y) == something)
		return (1);
	if (map_get_pixel(mlxdata, x + PROTECT, y + PROTECT) == something \
	&& map_get_pixel(mlxdata, x - PROTECT, y - PROTECT) == something)
		return (2);
	if (map_get_pixel(mlxdata, x - PROTECT, y + PROTECT) == something \
		&& map_get_pixel(mlxdata, x + PROTECT, y + PROTECT) == something)
		return (2);
	return (0);
}

double	ray_protect(t_mlxdata *mlxdata, double degrees, \
double position_x, double position_y)
{
	double			repeat;
	const double	sin_degree = ray_sin(degrees);
	const double	cos_degree = ray_cos(degrees);

	repeat = 0;
	while (1)
	{
		if (is_pairing(mlxdata, position_x + sin_degree * repeat, \
		position_y + cos_degree * repeat, WALL))
			break ;
		repeat += PROTECT;
	}
	return (repeat);
}

double	ray_tracing(t_mlxdata *mlxdata, double degrees, \
double position_x, double position_y)
{
	double			repeat;
	const double	sin_degree = ray_sin(degrees);
	const double	cos_degree = ray_cos(degrees);

	repeat = 0;
	while (1)
	{
		if (is_pairing(mlxdata, position_x + sin_degree * repeat, \
		position_y + cos_degree * repeat, WALL))
			break ;
		repeat += PROTECT;
	}
	mlxdata->side = ray_get_side(mlxdata, position_x + sin_degree * repeat, \
	position_y + cos_degree * repeat);
	mlxdata->percent = ray_get_percent(mlxdata->side, position_x + sin_degree * repeat, \
	position_y + cos_degree * repeat);
	return (repeat);
}

void	ray_tracing_full(t_mlxdata *mlxdata)
{
	int		x;
	double	distance;
	double	angle_start;
	double	angle_stop;

	x = 0;
	angle_start = mlxdata->player_angle - VISIBLE_RANGE / 2;
	angle_stop = mlxdata->player_angle + VISIBLE_RANGE / 2;
	while (angle_start < angle_stop && x <= SIZE_X)
	{
		distance = ray_tracing(mlxdata, angle_start, mlxdata->player_x, mlxdata->player_y) \
		* ray_cos(mlxdata->player_angle - angle_start);
		drawing_line(mlxdata, x, distance);
		angle_start += (double)VISIBLE_RANGE / (double)SIZE_X;
		x++;
	}
}
