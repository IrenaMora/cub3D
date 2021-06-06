#include "parser.h"
#include "../cub3d.h"

void	validate_extension(t_map *map_data)
{
	int		length;
	char	*input;

	input = map_data->input;
	length = ft_strlen(input);
	if (length < 4)
		define_error(map_data, ERROR_EXTENSION);
	if (!(input[length - 4] == '.' && input[length - 3] == 'c' \
	&& input[length - 2] == 'u' && input[length - 1] == 'b'))
		define_error(map_data, ERROR_EXTENSION);
}
