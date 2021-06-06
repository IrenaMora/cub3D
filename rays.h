#ifndef RAYS_H
# define RAYS_H

# include "cub3d.h"

double	ray_sin(double deg);
double	ray_cos(double deg);
int		ray_is_wall(t_mlxdata *mlxdata, int x, int y);
int		ray_get_side(t_mlxdata *mlxdata, double x, double y);
double	ray_get_percent(int side, double x, double y);
double	ray_tracing(t_mlxdata *mlxdata, double degrees, \
double position_x, double position_y);
void	ray_tracing_full(t_mlxdata *mlxdata);
double	ray_protect(t_mlxdata *mlxdata, double degrees, \
double position_x, double position_y);

#endif