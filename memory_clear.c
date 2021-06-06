#include "memory_clear.h"

void	lst_element_free(t_list *lst)
{
	free(lst->content);
	free(lst);
}

void	free_lst(t_list *lst_current)
{
	t_list	*lst_last;

	while (lst_current)
	{
		lst_last = lst_current;
		lst_current = lst_current->next;
		lst_element_free(lst_last);
	}
}

void	memory_mlxdata_clear(t_mlxdata *mlxdata, int mapdata_also)
{
	if (mlxdata->img.img)
		mlx_destroy_image(mlxdata->mlx, mlxdata->img.img);
	if (mlxdata->north.img)
		mlx_destroy_image(mlxdata->mlx, mlxdata->north.img);
	if (mlxdata->south.img)
		mlx_destroy_image(mlxdata->mlx, mlxdata->south.img);
	if (mlxdata->west.img)
		mlx_destroy_image(mlxdata->mlx, mlxdata->west.img);
	if (mlxdata->east.img)
		mlx_destroy_image(mlxdata->mlx, mlxdata->east.img);
	if (mlxdata->win)
		mlx_destroy_window(mlxdata->mlx, mlxdata->win);
	if (mapdata_also)
		memory_mapdata_clear(mlxdata->map_data);
	if (mlxdata)
		free(mlxdata);
}

void	memory_mapdata_clear(t_map *mapdata)
{
	int	y;

	y = 0;
	if (mapdata->map != NULL)
	{
		while (y < mapdata->size_y)
			free(mapdata->map[y++]);
		free(mapdata->map);
	}
	if (mapdata->line != NULL)
		free(mapdata->line);
	if (mapdata->NO != NULL)
		free(mapdata->NO);
	if (mapdata->SO != NULL)
		free(mapdata->SO);
	if (mapdata->WE != NULL)
		free(mapdata->WE);
	if (mapdata->EA != NULL)
		free(mapdata->EA);
}

void	define_error(t_map *map_data, char *error)
{
	printf("Error\n%s", error);
	memory_mapdata_clear(map_data);
	exit(0);
}
