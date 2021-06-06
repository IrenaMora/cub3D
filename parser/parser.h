#ifndef PARSER_H
# define PARSER_H

# include <stddef.h>
# include <stdlib.h>

# define ERROR_EXTENSION "Wrong extension of file."
# define ERROR_MAP_READ "Wrong read file."
# define ERROR_FEW_ELEMENTS "Not every element found."
# define ERROR_ARGS "Too many arguments."
# define ERROR_COLOR "Invalid color."
# define ERROR_COMMAND "Invalid command."
# define ERROR_FEW_COMMANDS "Too few commands before map."
# define ERROR_MALLOC "Memory allocation error."
# define ERROR_AFTER_MAP "Found commands after map."
# define ERROR_MAP_NOT_FOUND "Map not found."
# define ERROR_FEW_DATA "Too few data in file."
# define ERROR_MAP_CHAR "Found wrong chars in the map."
# define ERROR_PLAYER_COUNT "Player count is not ONE on the map."
# define ERROR_MAP_AROUND "Map must be surrounded by walls."
# define ERROR_PARAM_USED "Some command has already been used."

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_map
{
	char	**map;
	int		size_x;
	int		size_y;
	char	*line;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
	int		file_descriptor;
	int		gnl;
	char	*input;
}				t_map;

t_map	*parse_data(char *input);
int		parse_map(t_map *map_data);
void	define_error(t_map *map_data, char *error);
void	validate_map(t_map *mapdata);
void	validate_extension(t_map *map_data);
int		skip_spaces(t_map *map_data, int *position);
char	*get_next_arg(t_map *map_data, int *position, int comma);
char	*get_command(t_map *map_data, int *position);
int		is_empty_line(char *line);
void	parse_side(t_map *map_data, int *position, int *needly_line, char **to);
void	parse_color(t_map *map_data, int *position, int *needly_line, int *to);
int		handle_element(char *command, t_map *map_data, int *position, \
int *needly_line);
int		parse_element(t_map *map_data);
void	lines_map_parser(t_map *map_data, t_list **lst, t_list **lst_last);
void	map_to_array(t_map *map_data, t_list *lst);
int		line_to_array(const char *line, char ***map_array, int size, int pos);
void	protect_map(t_map *map_data, int max_x, int max_y);

int		create_trgb(int t, int r, int g, int b);
long	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, \
size_t dstsize);
int		ft_atoi(const char *str);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

#endif