# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malannys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 16:40:54 by malannys          #+#    #+#              #
#    Updated: 2019/04/07 16:40:55 by malannys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit
SRC := main.c reader.c
HDR := fillit.h
OBJ := $(SRC:.c=.o)
CC := gcc
CFLAGS := -Wall -Wextra -Werror

.PHONY: all fclean clean

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all