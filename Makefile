.PHONY	:	all clean fclean re

NAME	=	cub3D

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

HEADERS =	background.h cub3d.h drawing.h hooks.h map.h memory_clear.h player.h protect.h rays.h texture.h parser/get_next_line.h parser/parser.h

SRC		=	background.c cub3d.c drawing.c hooks.c main.c map.c memory_clear.c mlx_additions.c player.c protect.c rays_additions.c rays.c texture.c parser/ft_lstadd_back.c parser/ft_lstlast.c parser/ft_lstnew.c parser/ft_lstsize.c parser/functions.c parser/get_elements.c parser/get_next_line_utils.c parser/get_next_line.c parser/map_validator.c parser/parser_elements.c parser/parser_map.c parser/parser.c parser/protect_map.c parser/validator.c

OBJ		=	background.o cub3d.o drawing.o hooks.o main.o map.o memory_clear.o mlx_additions.o player.o protect.o rays_additions.o rays.o texture.o ft_lstadd_back.o ft_lstlast.o ft_lstnew.o ft_lstsize.o functions.o get_elements.o get_next_line_utils.o get_next_line.o map_validator.o parser_elements.o parser_map.o parser.o protect_map.o validator.o

all		:	$(NAME)

$(NAME)	:	$(SRC) $(HEADERS)
	cd minilibx && $(MAKE) all
	mv minilibx/libmlx.dylib libmlx.dylib
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libmlx.dylib -o $(NAME)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all