#include "cub3d.h"
#include "hooks.h"
#include "memory_clear.h"

t_mlxdata	*init_vars(t_map *map_data)
{
	t_mlxdata	*mlxdata;

	mlxdata = malloc(sizeof(t_mlxdata));
	if (!mlxdata)
	{
		memory_mlxdata_clear(mlxdata, 0);
		define_error(map_data, ERROR_MALLOC);
	}
	mlxdata->mlx = NULL;
	mlxdata->win = NULL;
	mlxdata->img.img = NULL;
	mlxdata->north.img = NULL;
	mlxdata->south.img = NULL;
	mlxdata->west.img = NULL;
	mlxdata->east.img = NULL;
	return (mlxdata);
}

void	init_set_addrs(t_mlxdata *mlxdata)
{
	mlxdata->img.addr = mlx_get_data_addr(mlxdata->img.img, &mlxdata->img.bits, \
	&mlxdata->img.line_length, &mlxdata->img.endian);
	mlxdata->north.addr = mlx_get_data_addr(mlxdata->north.img, &mlxdata->north.bits, \
	&mlxdata->north.line_length, &mlxdata->north.endian);
	mlxdata->south.addr = mlx_get_data_addr(mlxdata->south.img, &mlxdata->south.bits, \
	&mlxdata->south.line_length, &mlxdata->south.endian);
	mlxdata->west.addr = mlx_get_data_addr(mlxdata->west.img, &mlxdata->west.bits, \
	&mlxdata->west.line_length, &mlxdata->west.endian);
	mlxdata->east.addr = mlx_get_data_addr(mlxdata->east.img, &mlxdata->east.bits, \
	&mlxdata->east.line_length, &mlxdata->east.endian);
}

t_mlxdata	*cub3d_init(int size_x, int size_y, char *caption, t_map *map_data)
{
	t_mlxdata	*mlxdata;

	mlxdata = init_vars(map_data);
	mlxdata->mlx = mlx_init();
	mlxdata->win = mlx_new_window(mlxdata->mlx, size_x, size_y, caption);
	mlxdata->map_data = map_data;
	mlxdata->img.img = mlx_new_image(mlxdata->mlx, size_x, size_y);
	mlxdata->north.img = mlx_png_file_to_image(mlxdata->mlx,
			mlxdata->map_data->NO, &mlxdata->north.x, &mlxdata->north.y);
	mlxdata->south.img = mlx_png_file_to_image(mlxdata->mlx,
			mlxdata->map_data->SO, &mlxdata->south.x, &mlxdata->south.y);
	mlxdata->west.img = mlx_png_file_to_image(mlxdata->mlx,
			mlxdata->map_data->WE, &mlxdata->west.x, &mlxdata->west.y);
	mlxdata->east.img = mlx_png_file_to_image(mlxdata->mlx,
			mlxdata->map_data->EA, &mlxdata->east.x, &mlxdata->east.y);
	if (!mlxdata->img.img || !mlxdata->north.img || !mlxdata->south.img \
	|| !mlxdata->west.img || !mlxdata->east.img)
	{
		memory_mlxdata_clear(mlxdata, 0);
		define_error(map_data, ERROR_READ_FILES);
	}
	init_set_addrs(mlxdata);
	return (mlxdata);
}
