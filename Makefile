SOURCES = so_long.c
OBJECTS = $(SOURCES:.c=.o)
NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(OBJECTS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all