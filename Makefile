SOURCES = sources/so_long.c \
	sources/ft_split.c \
	sources/ft_strdup.c \
	sources/ft_strjoin.c \
	sources/get_next_line.c \
	sources/get_next_line_utils.c \
	sources/ft_substr.c \
	sources/ft_memmove.c \
	sources/ft_strlcpy.c \
	sources/ft_strlen.c

OBJECTS = $(SOURCES:.c=.o)
NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS) sources/so_long.h sources/get_next_line.h
	$(CC) $(OBJECTS) $(MLXFLAGS) -o $(NAME)

%.o: %.c sources/so_long.h sources/get_next_line.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
