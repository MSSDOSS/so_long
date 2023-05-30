# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 17:35:49 by hel-haia          #+#    #+#              #
#    Updated: 2023/05/29 20:07:45 by hel-haia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_memmove.c \
			  ft_strlen.c \
			  ft_strlcpy.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_split.c \
			  ft_putstr.c \
			  ft_putnbr.c \
			  ft_itoa.c \
		
OBJS		= $(SRCS:%.c=%.o)


FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c libft.h
	cc $(FLAGS) -c $<

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: all
	ar rc $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus
