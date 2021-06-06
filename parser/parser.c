#include <fcntl.h>
#include "parser.h"
#include "../cub3d.h"
#include "get_next_line.h"
#include "../memory_clear.h"

void	check_valid_map(t_map *map_data)
{
	int	x;
	int	y;
	int	c;
	int	player;

	x = 0;
	player = 0;
	while (x < map_data->size_x)
	{
		y = 0;
		while (y < map_data->size_y)
		{
			c = map_data->map[y][x];
			if (c != EMPTY && c != WALL && c != PLAYER_E && c != PLAYER_N \
			&& c != PLAYER_S && c != PLAYER_W && c != NO_ELEMENT)
				define_error(map_data, ERROR_MAP_CHAR);
			if (c == PLAYER_E || c == PLAYER_N || c == PLAYER_S \
			|| c == PLAYER_W)
				player++;
			y++;
		}
		x++;
	}
	if (player != 1)
		define_error(map_data, ERROR_PLAYER_COUNT);
}

void	check_valid_data(t_map *map_data, int map_checker)
{
	if (!map_data->NO || !map_data->SO || !map_data->WE || !map_data->EA \
	|| map_data->F == __INT_MAX__ || map_data->C == __INT_MAX__)
		define_error(map_data, ERROR_FEW_COMMANDS);
	if (map_checker)
	{
		if (map_data->map == NULL)
			define_error(map_data, ERROR_MAP_NOT_FOUND);
		check_valid_map(map_data);
		validate_map(map_data);
	}
}

t_map	*mapdata_init(char *input)
{
	t_map	*map_data;

	map_data = malloc(sizeof(t_map));
	if (!map_data)
		define_error(map_data, ERROR_MALLOC);
	map_data->map = NULL;
	map_data->line = NULL;
	map_data->NO = NULL;
	map_data->SO = NULL;
	map_data->WE = NULL;
	map_data->EA = NULL;
	map_data->F = __INT_MAX__;
	map_data->C = __INT_MAX__;
	map_data->file_descriptor = open(input, O_RDONLY);
	map_data->input = input;
	return (map_data);
}

void	lines_data_parser(t_map *map_data)
{
	while (map_data->gnl > 0)
	{
		if (!parse_element(map_data))
			break ;
		free(map_data->line);
		map_data->line = NULL;
		map_data->gnl = get_next_line(map_data->file_descriptor, \
		&map_data->line);
	}
}

t_map	*parse_data(char *input)
{
	t_map	*map_data;

	map_data = mapdata_init(input);
	validate_extension(map_data);
	map_data->gnl = get_next_line(map_data->file_descriptor, &map_data->line);
	lines_data_parser(map_data);
	if (map_data->map == NULL || map_data->size_y < 3 || map_data->size_x < 3)
		define_error(map_data, ERROR_FEW_DATA);
	while (map_data->gnl > 0)
	{
		if (!is_empty_line(map_data->line))
			define_error(map_data, ERROR_AFTER_MAP);
		free(map_data->line);
		map_data->gnl = get_next_line(map_data->file_descriptor, \
		&map_data->line);
	}
	if (map_data->line != NULL && !is_empty_line(map_data->line))
		define_error(map_data, ERROR_AFTER_MAP);
	if (map_data->gnl == -1)
		define_error(map_data, ERROR_MAP_READ);
	check_valid_data(map_data, 1);
	close(map_data->file_descriptor);
	protect_map(map_data, map_data->size_x, map_data->size_y);
	return (map_data);
}
