# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 13:28:22 by aaleixo-          #+#    #+#              #
#    Updated: 2025/03/09 13:28:22 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES = \
	srcs/handle.c srcs/main.c srcs/map_check.c \
	srcs/map.c srcs/move.c srcs/ren.c \
	srcs/utils.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux
ADLIBS = ./lib/ft_printf/libftprintf.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(ADLIBS):
	make -C ./minilibx-linux
	make -C ./lib/ft_printf

$(NAME): $(OBJECTS) $(ADLIBS)
	$(CC) $(CFLAGS) $(OBJECTS) $(ADLIBS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C ./lib/ft_printf clean
	make clean -C ./minilibx-linux

fclean: clean
	rm -f $(NAME)
	make clean -C ./lib/ft_printf
	make clean -C ./minilibx-linux

re: fclean all

.PHONY: all clean fclean re