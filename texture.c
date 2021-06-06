#include "cub3d.h"

void	texture_drawing(t_mlxdata *mlxdata, int x, int start, int end)
{
	double	count;
	int		pixel;
	double	scale;
	t_data	*texture;

	if (mlxdata->side == NORTH)
		texture = &mlxdata->north;
	else if (mlxdata->side == SOUTH)
		texture = &mlxdata->south;
	else if (mlxdata->side == WEST)
		texture = &mlxdata->west;
	else
		texture = &mlxdata->east;
	scale = (double)(end - start) / texture->y;
	if (scale < 0.0001)
		scale = 0.0001;
	count = 0;
	while (start < end)
	{
		pixel = mlx_pixel_get_f(texture, texture->x * mlxdata->percent, \
		count / scale);
		mlx_pixel_put_f(&mlxdata->img, x, start, pixel);
		count++;
		start++;
	}
}
