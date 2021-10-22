# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 23:50:03 by bcorrea-          #+#    #+#              #
#    Updated: 2021/10/07 23:50:06 by bcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=5
MAIN	= get_next_line.c get_next_line_utils.c


all:
	$(CC) $(CFLAGS) -c $(MAIN) -I ./ -o get_next_line.o

clean:
	rm -f get_next_line.o

re: clean all

debug:
	$(CC) $(CFLAGS) -g $(MAIN) -I./ -o debug

.PHONY: all clean re debug
