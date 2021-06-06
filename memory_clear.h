#ifndef MEMORY_CLEAR_H
# define MEMORY_CLEAR_H

# include "cub3d.h"
# include "parser/parser.h"

void	free_lst(t_list *lst_current);
void	lst_element_free(t_list *lst);
void	memory_mlxdata_clear(t_mlxdata *mlxdata, int mapdata_also);
void	memory_mapdata_clear(t_map *mapdata);
void	define_error(t_map *map_data, char *error);

#endif