#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

int	map_get_pixel(t_mlxdata *mlxdata, int x, int y);
int	map_get_color(int pixel);

#endif