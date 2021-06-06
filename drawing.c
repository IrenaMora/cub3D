#include "cub3d.h"
#include "map.h"
#include "rays.h"
#include "protect.h"
#include "texture.h"

void	drawing_re(t_mlxdata *mlxdata)
{
	protect_coordinates(mlxdata);
	ray_tracing_full(mlxdata);
	mlx_redraw_win(mlxdata);
}

void	drawing_line(t_mlxdata *mlxdata, int x, double distance)
{
	int	count;
	int	height;
	int	y_start;
	int	y_end;

	if (distance == 0)
		return ;
	count = 0;
	height = (SIZE_Y / distance * (SIZE_X / SIZE_Y)) * 2 / 3;
	y_start = -height * 0.5 + SIZE_Y * 0.5;
	while (count < y_start)
		mlx_pixel_put_f(&mlxdata->img, x, count++, mlxdata->map_data->C);
	y_end = SIZE_Y - y_start;
	texture_drawing(mlxdata, x, y_start, y_end);
	while (y_end < SIZE_Y)
		mlx_pixel_put_f(&mlxdata->img, x, y_end++, mlxdata->map_data->F);
}
