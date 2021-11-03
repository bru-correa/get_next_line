# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 23:50:03 by bcorrea-          #+#    #+#              #
#    Updated: 2021/11/03 06:53:07 by bcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=42
MAIN		= get_next_line.c get_next_line_utils.c
BONUS		= get_next_line_bonus.c get_next_line_utils_bonus.c

all:
	$(CC) $(CFLAGS) -c $(MAIN) -I ./ -o get_next_line.o

clean:
	rm -f get_next_line.o
	rm -f get_next_line_bonus.o

re: clean all

bonus:
	$(CC) $(CFLAGS) -c $(BONUS) -I ./ -o get_next_line_bonus.o

.PHONY: all clean re bonus
