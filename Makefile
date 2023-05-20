SOURCES	= sources/so_long.c \
	sources/drawing.c \
	sources/player_keys.c \
	sources/fill_struct.c \
	sources/hook_functions.c \
	sources/map_valid.c \
	sources/libft/ft_split.c \
	sources/libft/ft_strdup.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c \
	sources/libft/ft_substr.c \
	sources/libft/ft_memmove.c \
	sources/libft/ft_strlcpy.c \

OBJECTS	= $(SOURCES:.c=.o)
LIBFT	= sources/libft/libft.a
NAME	= so_long
CC		= cc
FLAGS	= -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT) sources/so_long.h sources/get_next_line.h sources/libft/libft.h
	$(CC) $(FLAGS) $(MLXFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

%.o: %.c sources/so_long.h sources/get_next_line.h sources/libft/libft.h
	$(CC) -g $(FLAGS) -Imlx -c $< -o $@

$(LIBFT):
	$(MAKE) -C sources/libft

clean:
	$(MAKE) -C sources/libft clean
	rm -rf $(OBJECTS)

fclean: clean
	$(MAKE) -C sources/libft fclean
	rm -rf $(NAME)

re: fclean all
