SOURCES	=	sources/so_long.c sources/drawing.c sources/fill_struct.c  \
			sources/map_valid.c sources/player_keys.c sources/hook_functions.c \
			sources/get_next_line.c sources/get_next_line_utils.c sources/directions.c

SOURCES_BNS	=	sources_bonus/so_long_bonus.c sources_bonus/drawing_bonus.c sources_bonus/fill_struct_bonus.c  \
			sources_bonus/map_valid_bonus.c sources_bonus/player_keys_bonus.c sources_bonus/hook_functions_bonus.c \
			sources_bonus/get_next_line.c sources_bonus/get_next_line_utils.c sources_bonus/directions_bonus.c

OBJECTS	= $(SOURCES:.c=.o)

OBJECTS_BNS	= $(SOURCES_BNS:.c=.o)

LIBFT	= sources/libft/libft.a
NAME	= so_long
NAME_BNS= so_long_bonus
CC		= cc
FLAGS	= -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

bonus : $(NAME_BNS)

$(NAME) : $(OBJECTS) $(LIBFT) sources/so_long.h
	$(CC) $(FLAGS) $(OBJECTS) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c sources/so_long.h sources_bonus/so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_BNS) : $(OBJECTS_BNS) $(LIBFT) sources_bonus/so_long_bonus.h
	$(CC) $(FLAGS) $(OBJECTS_BNS) $(MLXFLAGS) $(LIBFT) -o $(NAME_BNS)

$(LIBFT):
	$(MAKE) -C sources/libft

clean:
	$(MAKE) -C sources/libft clean
	rm -rf $(OBJECTS)
	rm -rf $(OBJECTS_BNS)

fclean: clean
	$(MAKE) -C sources/libft fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BNS)

re: fclean all bonus
