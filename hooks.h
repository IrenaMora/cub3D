#ifndef HOOKS_H
# define HOOKS_H

# include "cub3d.h"

int	keys_hook(int keycode, t_mlxdata *mlxdata);
int	init_hook(t_mlxdata *mlxdata);
int	my_hook(void *s_struct);
int	exit_hook(t_mlxdata *mlxdata);

#endif