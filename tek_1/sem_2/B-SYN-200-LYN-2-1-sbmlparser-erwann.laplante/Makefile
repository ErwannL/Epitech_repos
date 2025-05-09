##
## EPITECH PROJECT, 2022
## B-SYN-200-LYN-2-1-sbmlparser-erwann.laplante
## File description:
## Makefile
##

.PHONY : all, clean, fclean, re

NAME = SBMLparser

SRC =	$(wildcard src/*.c) \
		$(wildcard src/flag/*.c) \

OBJ =	$(SRC:.c=.o)

FLAGS = -L. -I./include/ -g3

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(FLAGS) $(OBJ)

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all
