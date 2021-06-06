#include "parser.h"
#include "../cub3d.h"
#include "get_next_line.h"
#include "../memory_clear.h"

int	skip_spaces(t_map *map_data, int *position)
{
	while (map_data->line[*position] == ' ')
		(*position)++;
	if (map_data->line[*position] == '\0')
		return (0);
	return (1);
}

char	*get_next_arg(t_map *map_data, int *position, int comma)
{
	int	start_pos;
	int	comma_char;

	start_pos = *position;
	comma_char = 0;
	if (comma)
		comma_char = ',';
	while (map_data->line[*position] != ' ' && map_data->line[*position] != '\0' \
	&& map_data->line[*position] != comma_char)
		(*position)++;
	if (comma && start_pos != *position && map_data->line[*position] != '\0')
		(*position)++;
	if (!skip_spaces(map_data, position))
		return (NULL);
	return (map_data->line + *position);
}

char	*get_command(t_map *map_data, int *position)
{
	if (!skip_spaces(map_data, position))
		return (NULL);
	return (map_data->line + *position);
}

int	is_empty_line(char *line)
{
	int	position;

	position = 0;
	while (line[position] == ' ')
		position++;
	if (line[position] == '\0')
		return (1);
	return (0);
}
