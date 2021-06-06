#include "cub3d.h"
#include "map.h"
#include "rays.h"
#include "hooks.h"
#include "player.h"
#include "protect.h"
#include "drawing.h"
#include "background.h"
#include "memory_clear.h"
#include "parser/parser.h"

int	main(int args_count, char **args)
{
	t_map		*map_data;
	t_mlxdata	*mlxdata;

	if (args_count - 1 != 1)
	{
		printf("Error\nWrong arguments count.");
		exit(0);
	}
	map_data = parse_data(args[1]);
	mlxdata = cub3d_init(SIZE_X, SIZE_Y, "Cub3D", map_data);
	player_init(mlxdata);
	mlx_hook(mlxdata->win, 2, (1L << 0), keys_hook, mlxdata);
	mlx_hook(mlxdata->win, 3, (1L << 1), keys_hook, mlxdata);
	mlx_hook(mlxdata->win, 17, 0L, exit_hook, mlxdata);
	mlx_loop_hook(mlxdata->mlx, init_hook, mlxdata);
	mlx_loop(mlxdata->mlx);
}
