CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=42
MAIN	= get_next_line.c get_next_line_utils.c


all:
	$(CC) $(CFLAGS) -c $(MAIN) -I ./ -o get_next_line.o

clean:
	rm -f get_next_line.o

re: clean all

.PHONY: all clean re
