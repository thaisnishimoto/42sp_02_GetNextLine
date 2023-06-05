# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 20:22:45 by tmina-ni          #+#    #+#              #
#    Updated: 2023/06/05 14:14:31 by tmina-ni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = $(wildcard ../*.c)

# Default BUFFER_SIZE value
BUFFER_SIZE ?= 1

all:
	$(CC) -g $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) test_gnl.c $(SRC) -lrt -lm -o $(NAME)
	./program

clean:
	rm -f *.o

fclean: clean
	rm -f program
