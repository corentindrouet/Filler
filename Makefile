# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 08:11:19 by cdrouet           #+#    #+#              #
#    Updated: 2016/04/27 09:22:22 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = main.c \

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
