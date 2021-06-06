#include "cub3d.h"
#include "memory_clear.h"
#include "protect.h"
#include "player.h"
#include "background.h"
#include "drawing.h"
#include "rays.h"
#include "texture.h"

int	keys_hook(int keycode, t_mlxdata *mlxdata)
{
	if (keycode == 53)
	{
		memory_mlxdata_clear(mlxdata, 1);
		exit(0);
	}
	else if (keycode == 13)
		player_move_ws(mlxdata, 0, mlxdata->player_x, mlxdata->player_y);
	else if (keycode == 1)
		player_move_ws(mlxdata, 180, mlxdata->player_x, mlxdata->player_y);
	else if (keycode == 2)
		player_move_ad(mlxdata, 90, mlxdata->player_x, mlxdata->player_y);
	else if (keycode == 0)
		player_move_ad(mlxdata, 270, mlxdata->player_x, mlxdata->player_y);
	else if (keycode == 124)
		player_turn(mlxdata, 1);
	else if (keycode == 123)
		player_turn(mlxdata, -1);
	else
		return (0);
	return (1);
}

int	init_hook(t_mlxdata *mlxdata)
{
	drawing_re(mlxdata);
	return (1);
}

int	exit_hook(t_mlxdata *mlxdata)
{
	memory_mlxdata_clear(mlxdata, 1);
	exit(0);
}
