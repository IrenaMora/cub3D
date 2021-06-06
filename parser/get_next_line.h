#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 100

int		get_next_line(int fd, char	**line);
long	ft_strlen(const char *str);
char	*get_remainder(char *buf);
char	*add_to_line(char *buf, char **line);
void	gnl_free_allocate(char **line, char **buf);

#endif
