##
## EPITECH PROJECT, 2023
## tech2
## File description:
## Makefile
##

NAME = zappy_server

SRC = $(wildcard src/*.c) \
		$(wildcard src/modular/*.c)	\
		$(wildcard src/commands/gui/*.c)	\
		$(wildcard src/commands/ai/*.c)	\
		$(wildcard src/modular/user/*.c)	\
		$(wildcard src/resources/*.c)	\
		$(wildcard src/tiles/*.c)	\
		$(wildcard src/time_unit/*.c)	\
		$(wildcard src/time_loop/*.c)	\
		$(wildcard lib/*.c)

OBJ = $(SRC:.c=.o)

CFLAGS += -std=gnu17 -Wall -Wextra -g3 -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(LDFLAGS) $^ -o $@
		mv $(NAME) ../

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../$(NAME)

re: fclean all
