# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 20:08:05 by clynderl          #+#    #+#              #
#    Updated: 2019/11/04 20:14:36 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

SRCS =		srcs/ft_list.c \
			srcs/main.c \
			srcs/parse.c \
			srcs/solve.c
OBJS = ft_list.o main.o parse.o solve.o

all: $(NAME)

$(NAME): lib $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

$(OBJS):
		$(CC) $(CFLAGS) -c $(SRCS) -I includes/ -I libft/includes/

lib:
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
		/bin/rm -rf $(NAME)
		make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
