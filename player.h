#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

void	player_init(t_mlxdata *mlxdata);
void	player_turn(t_mlxdata *mlxdata, int side);
void	player_move_ws(t_mlxdata *mlxdata, int side, \
double update_x, double update_y);
void	player_move_ad(t_mlxdata *mlxdata, int side, \
double update_x, double update_y);

#endif
