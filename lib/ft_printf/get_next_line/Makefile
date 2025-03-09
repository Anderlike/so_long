# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 14:05:34 by aaleixo-          #+#    #+#              #
#    Updated: 2025/03/09 14:09:48 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ../ft_printf/libft
	make bonus -C  ../ft_printf/libft
	ar rsc $(NAME) $(OBJS)  libft/*.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	make clean -C ../ft_printf/libft

fclean: clean
	@rm -f $(NAME)
	make fclean -C ../ft_printf/libft

re: fclean all