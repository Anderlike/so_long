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
	srcs/utils.c srcs/path_check.c
OBJECTS = $(SOURCES:.c=.o)

MAKE_PRINTF = make -C ./lib/ft_printf
MAKE_MINILIBX = make -C ./minilibx-linux

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux
ADLIBS = ./lib/ft_printf/libftprintf.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(ADLIBS):
	$(MAKE_MINILIBX)
	$(MAKE_PRINTF)

$(NAME): $(OBJECTS) $(ADLIBS)
	$(CC) $(CFLAGS) $(OBJECTS) $(ADLIBS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE_MINILIBX) clean
	$(MAKE_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re