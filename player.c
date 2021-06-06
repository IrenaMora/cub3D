#include "cub3d.h"
#include "map.h"
#include "rays.h"
#include "drawing.h"
#include "protect.h"

int	player_is_found(t_mlxdata *mlxdata, int pixel, int x, int y)
{
	if (pixel == PLAYER_W || pixel == PLAYER_S \
	|| pixel == PLAYER_N || pixel == PLAYER_E)
	{
		if (pixel == PLAYER_N)
			mlxdata->player_angle = 270;
		else if (pixel == PLAYER_S)
			mlxdata->player_angle = 90;
		else if (pixel == PLAYER_W)
			mlxdata->player_angle = 180;
		else
			mlxdata->player_angle = 360;
		mlxdata->player_x = x + 0.5;
		mlxdata->player_y = y + 0.5;
		return (1);
	}
	return (0);
}

void	player_init(t_mlxdata *mlxdata)
{
	int	x;
	int	y;
	int	pixel;

	x = 0;
	while (x < mlxdata->map_data->size_x)
	{
		y = 0;
		while (y < mlxdata->map_data->size_y)
		{
			pixel = map_get_pixel(mlxdata, x, y);
			if (player_is_found(mlxdata, pixel, x, y))
				return ;
			y++;
		}
		x++;
	}
}

void	player_turn(t_mlxdata *mlxdata, int side)
{
	double	count;

	count = 0;
	while (count < TURN_STEP_ALL)
	{
		if (side == 1)
			mlxdata->player_angle += TURN_STEP;
		else if (side == -1)
			mlxdata->player_angle -= TURN_STEP;
		count += TURN_STEP;
	}
}

void	player_move_ws(t_mlxdata *mlxdata, int side, \
double update_x, double update_y)
{
	double	count;
	int		side_goto;

	count = 0;
	if (side == 0)
		side_goto = 1;
	else if (side == 180)
		side_goto = -1;
	while (count < STEP)
	{
		if (!protect_player_outside(mlxdata, mlxdata->player_angle \
		+ side, update_x, update_y))
			break ;
		update_x = mlxdata->player_x + side_goto * ray_sin(mlxdata->player_angle) \
		* count / STEP;
		update_y = mlxdata->player_y + side_goto * ray_cos(mlxdata->player_angle) \
		* count / STEP;
		count += PROTECT;
	}
	mlxdata->player_x = update_x;
	mlxdata->player_y = update_y;
}

void	player_move_ad(t_mlxdata *mlxdata, int side, \
double update_x, double update_y)
{
	double	count;
	int		side_goto;

	count = 0;
	if (side == 90)
		side_goto = 1;
	else if (side == 270)
		side_goto = -1;
	while (count < STEP / 3)
	{
		if (!protect_player_outside(mlxdata, mlxdata->player_angle \
		+ side, update_x, update_y))
			break ;
		update_x = mlxdata->player_x + side_goto * ray_cos(mlxdata->player_angle) \
		* count / STEP;
		update_y = mlxdata->player_y - side_goto * ray_sin(mlxdata->player_angle) \
		* count / STEP;
		count += PROTECT;
	}
	mlxdata->player_x = update_x;
	mlxdata->player_y = update_y;
}
