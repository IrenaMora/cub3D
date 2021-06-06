#ifndef PROTECT_H
# define PROTECT_H

# include "cub3d.h"

void	protect_coordinates(t_mlxdata *mlxdata);
int		protect_drawing(int x, int y);
int		protect_player_outside(t_mlxdata *mlxdata, int angle, \
double x, double y);
int		protect_ray_outside(double x, double y);
double	protect_degrees(double degrees);

#endif
