#include "cub3d.h"

void	background_init(t_mlxdata *mlxdata)
{
	int	x;
	int	y;

	x = 0;
	while (x < SIZE_X)
	{
		y = 0;
		while (y < SIZE_Y)
		{
			mlx_pixel_put_f(&mlxdata->img, x, y, COLOR_STANDART);
			y++;
		}
		x++;
	}
}
