#include "cub3d.h"
#include "protect.h"

void	mlx_redraw_win(t_mlxdata *mlxdata)
{
	mlx_put_image_to_window(mlxdata->mlx, mlxdata->win, mlxdata->img.img, 0, 0);
}

void	mlx_pixel_put_f(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!protect_drawing(x, y))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

int	mlx_pixel_get_f(t_data *data, int x, int y)
{
	char	*dst;

	if (!protect_drawing(x, y))
		return (0);
	if (x == 0 && y == 0)
		return (0);
	dst = data->addr + (y * data->line_length + x * (data->bits / 8));
	return (*(unsigned int *)dst);
}
