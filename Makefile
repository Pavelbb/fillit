# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 20:08:05 by clynderl          #+#    #+#              #
#    Updated: 2019/11/10 16:05:13 by clynderl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
OBJS =		ft_list.o main.o parse.o solve.o tetri.o free_funcs.o
LIB =		libft/libft.a

all: $(NAME)

ft_list.o: srcs/ft_list.c
	$(CC) $(CFLAGS) -c srcs/ft_list.c -o ft_list.o -I includes -I libft/includes/
main.o: srcs/main.c
	$(CC) $(CFLAGS) -c srcs/main.c -o main.o -I includes -I libft/includes/
parse.o: srcs/parse.c
	$(CC) $(CFLAGS) -c srcs/parse.c -o parse.o -I includes -I libft/includes/
solve.o: srcs/solve.c
	$(CC) $(CFLAGS) -c srcs/solve.c -o solve.o -I includes -I libft/includes/
tetri.o: srcs/tetri.c
	$(CC) $(CFLAGS) -c srcs/tetri.c -o tetri.o -I includes -I libft/includes/
free_funcs.o: srcs/free_funcs.c
	$(CC) $(CFLAGS) -c srcs/free_funcs.c -o free_funcs.o -I includes -I libft/includes/


$(NAME): $(LIB) $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L libft/ -lft

$(LIB):
	make -C libft

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
		/bin/rm -rf $(NAME)
		make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
