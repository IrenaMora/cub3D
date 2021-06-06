#include <fcntl.h>
#include "parser.h"
#include "../cub3d.h"
#include "get_next_line.h"
#include "../memory_clear.h"

int	line_to_array(const char *line, char ***map_array, int size, int pos)
{
	int	current;
	int	line_size;

	current = 0;
	line_size = ft_strlen(line);
	(*map_array)[pos] = malloc(size + 1);
	if (!(*map_array)[pos])
		return (0);
	while (current < line_size)
	{
		if (line[current] != ' ')
			(*map_array)[pos][current] = line[current];
		else
			(*map_array)[pos][current] = NO_ELEMENT;
		current++;
	}
	while (current < size)
		(*map_array)[pos][current++] = NO_ELEMENT;
	(*map_array)[pos][current] = '\0';
	return (1);
}

void	map_to_array(t_map *map_data, t_list *lst)
{
	int		pos;
	t_list	*lst_current;
	t_list	*lst_last;
	char	**map_array;

	pos = 0;
	map_data->size_y = ft_lstsize(lst);
	lst_current = lst;
	map_array = malloc(sizeof(char *) * map_data->size_y);
	if (!map_array)
	{
		free_lst(lst);
		define_error(map_data, ERROR_MALLOC);
	}
	while (lst_current != NULL)
	{
		if (!line_to_array(lst_current->content, &map_array, \
		map_data->size_x, pos))
			define_error(map_data, ERROR_MALLOC);
		lst_last = lst_current;
		lst_current = lst_current->next;
		lst_element_free(lst_last);
		pos++;
	}
	map_data->map = map_array;
}

void	lines_map_parser(t_map *map_data, t_list **lst, t_list **lst_last)
{
	while (1)
	{
		map_data->gnl = get_next_line(map_data->file_descriptor, \
		&map_data->line);
		if (is_empty_line(map_data->line))
		{
			free(map_data->line);
			break ;
		}
		if (map_data->size_x < ft_strlen(map_data->line))
			map_data->size_x = ft_strlen(map_data->line);
		*lst_last = ft_lstnew(map_data->line);
		if (!*lst_last)
		{
			free_lst(*lst);
			define_error(map_data, ERROR_MALLOC);
		}
		ft_lstadd_back(lst, *lst_last);
		if (map_data->gnl != 1)
			break ;
	}
}

int	parse_map(t_map *map_data)
{
	t_list	*lst;
	t_list	*lst_last;

	lst = ft_lstnew(map_data->line);
	map_data->size_x = ft_strlen(map_data->line);
	if (!lst)
		define_error(map_data, ERROR_MALLOC);
	lines_map_parser(map_data, &lst, &lst_last);
	if (map_data->gnl == -1)
		define_error(map_data, ERROR_MAP_READ);
	map_to_array(map_data, lst);
	if (map_data->gnl != 0)
	{
		map_data->gnl = get_next_line(map_data->file_descriptor, \
		&map_data->line);
	}
	else
		map_data->line = NULL;
	return (0);
}
