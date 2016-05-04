# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 08:11:19 by cdrouet           #+#    #+#              #
#    Updated: 2016/05/04 13:59:41 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c \
	  init_map.c \
	  get_data.c \
	  t_pt_lst.c \
	  lst_function.c \

BIN = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIB = -Llibft/ -lftprintf

MLIB = make -C libft/

$(NAME) :
	gcc $(FLAG) -c $(SRC);
	gcc $(FLAG) -o $(NAME) $(BIN) $(LIB)

all : $(NAME)

clean : 
	rm -f $(BIN)

fclean : clean
	rm -f $(NAME)

re : fclean all
