# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/28 20:22:45 by tmina-ni          #+#    #+#              #
#    Updated: 2023/05/28 22:22:49 by tmina-ni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
CC = cc
CFLAGS = -Wall -Wextra -Werror

test_%:
	$(CC) $(CFLAGS) $@.c -lrt -lm -o $(NAME)
	./program

clean:
	rm -f *.o

fclean: clean
	rm -f program
