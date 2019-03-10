# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:48:14 by bdomansk          #+#    #+#              #
#    Updated: 2018/10/03 14:41:18 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN = lem-in
LIB = libft/libft.a
LIBDIR = libft
SRC = main.c init_info.c put_manual.c error.c check_rooms_and_links.c \
	  words_utilits.c check_link.c check_route.c check_filling.c \
	  check_input.c make_adjacency_lists.c num_rooms.c algoritm.c \
	  get_queue.c bonuses.c paths.c free_queue.c get_path.c check_music.c \
	  moves.c simple_moves.c execute_moves.c colours.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
HEADER = lemin.h
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(LEM_IN)

$(LEM_IN) : $(LIB) $(OBJ)
	@echo "lem-in creating"
	@gcc $(FLAGS) $(OBJ) -o $(LEM_IN) $(LIB)
	@echo "\033[32mUse ./lem-in -h to see the usage"

$(OBJ): $(SRC)
	@echo "Lem-in objects creating"
	@gcc $(FLAGS) -c $(SRC)

$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(OBJ)
	@echo "Clean lem-in objects"
	@make -C $(LIBDIR)/ clean
n :
	@norminette $(HEADER)
	@norminette $(SRC)

fclean:
	@make -C $(LIBDIR)/ fclean
	@$(DEL) $(OBJ)
	@$(DEL) $(LEM_IN)

re: fclean all

