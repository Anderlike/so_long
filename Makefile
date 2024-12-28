# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 17:47:40 by aaleixo-          #+#    #+#              #
#    Updated: 2024/11/19 17:47:40 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SOURCES = \
	main.c initializer.c map_maker.c image_handler.c utils.c utils_2.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./minilibx-linux
ADLIBS = ./lib/ft_printf/libftprintf.a
MLX_FLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJECTS) $(ADLIBS)
	$(CC) $(CFLAGS) $(OBJECTS) $(ADLIBS) $(MLX_FLAGS) -o $(NAME)

$(ADLIBS):
	make -C ./lib/ft_printf
	make -C ./minilibx-linux 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C ./lib/ft_printf clean
	make -C ./minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C ./lib/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re