#include "parser.h"
#include "../cub3d.h"
#include "get_next_line.h"
#include "../memory_clear.h"

void	parse_side(t_map *map_data, int *position, int *needly_line, char **to)
{
	char	*arg_start;
	char	*arg;
	int		end_position;

	if (*to)
		define_error(map_data, ERROR_PARAM_USED);
	*needly_line = 1;
	end_position = 0;
	arg_start = get_next_arg(map_data, position, 0);
	while (arg_start[end_position] != '\0' && arg_start[end_position] != ' ')
		end_position++;
	arg = malloc(end_position + 1);
	if (!arg)
		define_error(map_data, ERROR_MALLOC);
	ft_strlcpy(arg, arg_start, end_position + 1);
	*to = arg;
}

int	safe_parse_color(t_map *map_data, int *position, int comma)
{
	int		value;
	char	*arg;

	arg = get_next_arg(map_data, position, comma);
	if (!arg)
		define_error(map_data, ERROR_COLOR);
	value = ft_atoi(arg);
	if (value > 255 || value == -1)
		define_error(map_data, ERROR_COLOR);
	return (value);
}

void	parse_color(t_map *map_data, int *position, int *needly_line, int *to)
{
	int		r;
	int		g;
	int		b;

	if (*to != __INT_MAX__)
		define_error(map_data, ERROR_PARAM_USED);
	*needly_line = 2;
	r = safe_parse_color(map_data, position, 0);
	g = safe_parse_color(map_data, position, 1);
	b = safe_parse_color(map_data, position, 1);
	*to = create_trgb(0, r, g, b);
}

int	handle_element(char *command, t_map *map_data, int *position, \
int *needly_line)
{
	if (command == NULL)
		return (1);
	if (!ft_strncmp(command, "NO ", 3))
		parse_side(map_data, position, needly_line, &map_data->NO);
	else if (!ft_strncmp(command, "SO ", 3))
		parse_side(map_data, position, needly_line, &map_data->SO);
	else if (!ft_strncmp(command, "WE ", 3))
		parse_side(map_data, position, needly_line, &map_data->WE);
	else if (!ft_strncmp(command, "EA ", 3))
		parse_side(map_data, position, needly_line, &map_data->EA);
	else if (!ft_strncmp(command, "F ", 2))
		parse_color(map_data, position, needly_line, &map_data->F);
	else if (!ft_strncmp(command, "C ", 2))
		parse_color(map_data, position, needly_line, &map_data->C);
	else
		return (parse_map(map_data));
	return (1);
}

int	parse_element(t_map *map_data)
{
	char	*command;
	int		position;
	int		needly_line;

	position = 0;
	needly_line = 0;
	command = get_command(map_data, &position);
	if (!handle_element(command, map_data, &position, &needly_line))
		return (0);
	if (needly_line == 1 && get_next_arg(map_data, &position, 0) != NULL)
		define_error(map_data, ERROR_ARGS);
	else if (needly_line == 2 && get_next_arg(map_data, &position, 1) != NULL)
		define_error(map_data, ERROR_ARGS);
	return (1);
}
