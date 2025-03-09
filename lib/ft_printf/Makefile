# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 11:29:01 by aaleixo-          #+#    #+#              #
#    Updated: 2025/03/09 14:07:32 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putnbr.c ft_ptr.c 
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft/
	make bonus -C  ./libft
	ar rsc $(NAME) $(OBJS)  libft/*.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	make -C ./libft fclean

re: fclean all