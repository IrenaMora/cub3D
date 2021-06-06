#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "parser/parser.h"

# define ERROR_READ_FILES "Wrong read files."

# define SIZE_X 1600
# define SIZE_Y 1000

# define VISIBLE_RANGE 60

# define STEP 0.1
# define TURN_STEP 1
# define TURN_STEP_ALL 3
# define PROTECT 0.01

# define UNKNOWN_RESULT 0
# define NO_ELEMENT 'e'

# define EMPTY '0'
# define WALL '1'
# define PLAYER_N 'N'
# define PLAYER_S 'S'
# define PLAYER_E 'E'
# define PLAYER_W 'W'

typedef enum e_map_colors
{
	COLOR_EMPTY = 0x5065DE,
	COLOR_CEILING = 0xFFFFFF,
	COLOR_WALL = 0xE77023,
	COLOR_FLOOR = 0xFFFFFF,
	COLOR_PLAYER = 0xE0CDC0,
	COLOR_TRACE = 0x735F52,
	COLOR_STANDART = 0xFFFFFF
}				t_map_colors;

typedef enum e_sides
{
	NORTH = 1,
	SOUTH = 2,
	WEST = 3,
	EAST = 4
}				t_sides;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_data;

typedef struct s_mlxdata
{
	t_map	*map_data;
	void	*mlx;
	void	*win;
	t_data	img;
	int		side;
	double	percent;
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
	double	player_x;
	double	player_y;
	int		player_angle;
}				t_mlxdata;

t_mlxdata	*cub3d_init(int size_x, int size_y, char *caption, t_map *map_data);
void		mlx_pixel_put_f(t_data *data, int x, int y, int color);
void		mlx_redraw_win(t_mlxdata *mlxdata);
int			mlx_pixel_get_f(t_data *data, int x, int y);

#endif
